#!/usr/bin/env python3

from os import listdir, makedirs, remove
from os.path import isfile, isdir, join
from random import choice
from subprocess import call, Popen, PIPE, TimeoutExpired
from sys import argv, stderr

TEST_SRC_PATH = "test/src"
TEST_BIN_PATH = "test/bin"
LINKER_FILE = "test/src/linker.ld"
DEFAULT_SIMULATOR = "bin/simulator"

AUTHORS = ["js4416", "pvk16"]

MIPS_CC = "mips-linux-gnu-gcc"
MIPS_CCFLAGS = "-W -Wall -fno-builtin -march=mips1 -mfp32 -fno-stack-protector"
MIPS_LDFLAGS = "-nostdlib -Wl,-melf32btsmip -march=mips1 " \
               "-nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none"
MIPS_OBJCOPY = "mips-linux-gnu-objcopy"

# Parse command line arg for simulator to use
try:
    simulator = argv[1]
except IndexError:
    simulator = DEFAULT_SIMULATOR
# Check simulator and tests exist
if not isfile(simulator):
    print(" ".join(["The simulator binary " + simulator + " does not exist"]), file=stderr)
    exit(1)
if not isdir(TEST_SRC_PATH):
    print(" ".join(["The test sources path" + TEST_SRC_PATH + " does not exist"]), file=stderr)
    exit(1)
if not isdir(TEST_BIN_PATH):
    makedirs(TEST_BIN_PATH)
# Setup counts
passed_count = 0
skipped_count = 0
failed_count = 0
# Iterate through tests
for f in sorted(listdir(TEST_SRC_PATH)):
    if isfile(join(TEST_SRC_PATH, f)) and (f.endswith(".c") or f.endswith(".s")):
        test_name = f.rsplit(".", 1)[0]
        # Generate binary
        source = ""
        if f.endswith(".s"):
            source = join(TEST_SRC_PATH, "{}.s".format(test_name))
        else:
            source = join(TEST_SRC_PATH, "{}.c".format(test_name))
        obj = join(TEST_BIN_PATH, "{}.mips.o".format(test_name))
        elf = join(TEST_BIN_PATH, "{}.mips.elf".format(test_name))
        binary = join(TEST_BIN_PATH, "{}.mips.bin".format(test_name))
        rc = call(" ".join([MIPS_CC,
                            MIPS_CCFLAGS,
                            "-c", source,
                            "-o", obj]),
                  shell=True)
        if rc != 0:
            print("Failed to compile the test source " + source, file=stderr)
            skipped_count += 1
            continue
        rc = call(" ".join([MIPS_CC,
                            MIPS_CCFLAGS,
                            MIPS_LDFLAGS,
                            "-T", LINKER_FILE, obj,
                            "-o", elf]),
                  shell=True)
        if rc != 0:
            print("Failed to link the test object  " + obj, file=stderr)
            skipped_count += 1
            continue
        rc = call(" ".join([MIPS_OBJCOPY,
                            "-O binary",
                            "--only-section=.text",
                            elf,
                            binary]),
                  shell=True)
        if rc != 0:
            print("Failed to copy the test elf  " + elf, file=stderr)
            skipped_count += 1
            continue
        remove(obj)
        remove(elf)
        # Get testing info
        expected_exit_code = 0
        description = ""
        with open(source, "r") as source_file:
            lines = source_file.readlines()
            try:
                expected_exit_code = int(lines[0].split("exit code: ")[-1])
                description = lines[1].split("description: ")[-1].strip()
            except ValueError or IndexError:
                print("The input file " + source + " is not correctly formatted", file=stderr)
                skipped_count += 1
                continue
        # Get testing input
        test_input = ""
        inputs = join(TEST_SRC_PATH, "{}.in".format(test_name))
        if isfile(inputs):
            with open(inputs, "rb") as input_file:
                test_input = input_file.read()
        # Get expected output
        expected_output = b""
        outputs = join(TEST_SRC_PATH, "{}.out".format(test_name))
        if isfile(outputs):
            with open(outputs, "rb") as output_file:
                expected_output = output_file.read()
        # Run test
        test_process = Popen(" ".join([simulator, binary]),
                             stdin=PIPE,
                             stderr=PIPE,
                             stdout=PIPE,
                             shell=True)
        test_output = ""
        test_exit_code = 0
        test_timeout = False
        try:
            test_output, _ = test_process.communicate(test_input, 5)
            test_exit_code = test_process.returncode
        except TimeoutExpired:
            test_process.kill()
            test_timeout = True
        # Check result
        test_passed = (not test_timeout) and test_exit_code == expected_exit_code % 256 and test_output == expected_output
        if test_passed:
            passed_count += 1
        else:
            failed_count += 1
        # Print CSV result line to stdout
        print(", ".join([test_name.upper(),
                         test_name.split("-")[0].upper(),
                         "Pass" if test_passed else "Fail",
                         choice(AUTHORS),
                         description]))
        # Print error messages to stderr
        if test_timeout:
            print("\033[0;1;31m" +
                  "Failed test: " +
                  test_name.upper() +
                  ": " + description + "\n" +
                  "Reason: Timeout after 5 seconds " +
                  "\033[0m", file=stderr)
        elif test_exit_code != expected_exit_code % 256:
            print("\033[0;1;31m" +
                  "Failed test: " +
                  test_name.upper() +
                  ": " + description + "\n" +
                  "Reason: Expected exit code " + str(expected_exit_code % 256) +
                  " but got " + str(test_exit_code) +
                  "\033[0m", file=stderr)
        elif test_output != expected_output:
            print("\033[0;1;31m" +
                  "Failed test: " +
                  test_name.upper() +
                  " (" + description + ")\n" +
                  "Reason: Expected output: \"" + "".join(map(chr, expected_output)) +
                  "\" but got \"" + "".join(map(chr, test_output)) + "\"" +
                  "\033[0m", file=stderr)
# Print summary to stderr
summary = []
print("\033[0;1;32m" + str(passed_count) + " " + ("test" if passed_count == 1 else "tests") + " passed" + "\033[0m",
      file=stderr)
if failed_count > 0:
    summary.append(str(failed_count) + " " + ("test" if failed_count == 1 else "tests") + " failed")
if skipped_count > 0:
    summary.append(str(skipped_count) + " " + ("test" if skipped_count == 1 else "tests") + " skipped")
print("\033[0;1;31m" + " and ".join(summary) + "\033[0m", file=stderr)
