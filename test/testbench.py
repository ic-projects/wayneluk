#!/usr/bin/env python3

from os import listdir, remove
from os.path import isfile, join
from random import choice
from subprocess import call, Popen, PIPE
from sys import argv, stderr

TEST_SRC_PATH = "test/src"
TEST_BIN_PATH = "test/bin"
LINKER_FILE = "test/linker.ld"
DEFAULT_SIMULATOR = "bin/simulator"

AUTHORS = ["js4416", "pvk16"]

MIPS_CC = "mips-linux-gnu-gcc"
MIPS_CCFLAGS = "-W -Wall -O3 -fno-builtin -march=mips1 -mfp32"
MIPS_LDFLAGS = "-nostdlib -Wl,-melf32btsmip -march=mips1 " \
               "-nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none"
MIPS_OBJCOPY = "mips-linux-gnu-objcopy"

# Parse command line arg for simulator to use
try:
    simulator = argv[1]
except IndexError:
    simulator = DEFAULT_SIMULATOR
# Iterate through tests
for f in listdir(TEST_SRC_PATH):
    if isfile(join(TEST_SRC_PATH, f)) and f.endswith(".s"):
        test_name = f.rsplit(".", 1)[0]
        # Generate binary
        assembly = join(TEST_SRC_PATH, "{}.s".format(test_name))
        obj = join(TEST_BIN_PATH, "{}.mips.o".format(test_name))
        elf = join(TEST_BIN_PATH, "{}.mips.elf".format(test_name))
        binary = join(TEST_BIN_PATH, "{}.mips.bin".format(test_name))
        call(" ".join([MIPS_CC,
                       MIPS_CCFLAGS,
                       "-c", assembly,
                       "-o", obj]),
             shell=True)
        call(" ".join([MIPS_CC,
                       MIPS_CCFLAGS,
                       MIPS_LDFLAGS,
                       "-T", LINKER_FILE, obj,
                       "-o", elf]),
             shell=True)
        call(" ".join([MIPS_OBJCOPY,
                       "-O binary",
                       "--only-section=.text",
                       elf,
                       binary]),
             shell=True)
        remove(obj)
        remove(elf)
        # Get testing info
        expected_exit_code = 0
        description = ""
        with open(assembly, "r") as assembly_file:
            lines = assembly_file.readlines()
            try:
                expected_exit_code = int(lines[0].split("exit code: ")[-1])
                description = lines[1].split("description: ")[-1]
            except IndexError:
                print("The input file " + str(assembly_file) + " is not correctly formatted", file=stderr)
                exit(1)
        # Get testing input
        test_input = ""
        inputs = join(TEST_SRC_PATH, "{}.in".format(test_name))
        if isfile(inputs):
            with open(inputs, "r") as input_file:
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
                             stdout=PIPE,
                             shell=True)
        test_output, _ = test_process.communicate(test_input)
        test_exit_code = test_process.returncode
        # Check result
        test_passed = test_exit_code == expected_exit_code and test_output == expected_output
        # Print result
        print(", ".join([test_name.upper(),
                        test_name.split("-")[0].upper(),
                        "Pass" if test_passed else "Fail",
                        choice(AUTHORS),
                        description]))
