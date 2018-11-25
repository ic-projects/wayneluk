#!/usr/bin/env python3

from os import listdir, makedirs, remove
from os.path import isfile, isdir, join
from random import choice
from subprocess import call, Popen, PIPE, TimeoutExpired
from sys import argv, stderr

TEST_SRC_PATH = "test/src"
TEST_BIN_PATH = "test/bin"
DEFAULT_SIMULATOR = "build/simulator"
AUTHORS = ["js4416", "pvk16"]

TEST_TIMEOUT_IN_SECONDS = 10


def print_msg(msg):
    print("\033[0;1;32m{}\033[0m".format(msg), file=stderr)


def print_err(msg):
    print("\033[0;1;31m{}\033[0m".format(msg), file=stderr)


# Parse command line arg for simulator to use
simulator = DEFAULT_SIMULATOR
if len(argv) > 1:
    simulator = argv[1]
# Check simulator and tests exist
if not isfile(simulator):
    print("The simulator binary {} does not exist".format(simulator), file=stderr)
    exit(1)
if not isdir(TEST_SRC_PATH):
    print("The test sources path {} does not exist".format(TEST_SRC_PATH), file=stderr)
    exit(1)
if not isdir(TEST_BIN_PATH):
    makedirs(TEST_BIN_PATH)
# Setup counts
passed_count = 0
skipped_count = 0
failed_count = 0
# Iterate through tests
for f in sorted(listdir(TEST_SRC_PATH)):
    if isfile(join(TEST_SRC_PATH, f)):
        test_name = f.rsplit(".", 1)[0]
        # Check this is a source file
        source = ""
        if f.endswith(".s"):
            source = join(TEST_SRC_PATH, "{}.s".format(test_name))
        elif f.endswith(".c"):
            source = join(TEST_SRC_PATH, "{}.c".format(test_name))
        else:
            continue
        # Generate binary
        binary = join(TEST_BIN_PATH, "{}.mips.bin".format(test_name))
        make_process = Popen("make {}".format(binary),
                             stdout=PIPE,
                             stderr=PIPE,
                             shell=True)
        _, make_errs = make_process.communicate()
        make_exit_code = make_process.returncode
        if make_exit_code != 0:
            print_err("Failed to compile the test source {}".format(source))
            print_err("Reason: {}".format("".join(map(chr, make_errs))))
            skipped_count += 1
            continue
        # Get testing info
        expected_exit_code = 0
        description = ""
        with open(source, "r") as source_file:
            lines = source_file.readlines()
            try:
                expected_exit_code = int(lines[0].split("exit code: ")[-1]) % 256
                description = lines[1].split("description: ")[-1].strip()
            except (ValueError, IndexError):
                print_err("The input file {} is not correctly formatted".format(source))
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
        test_process = Popen("{} {}".format(simulator, binary),
                             stdin=PIPE,
                             stdout=PIPE,
                             stderr=PIPE,
                             shell=True)
        test_output = b""
        test_exit_code = 0
        test_timeout = False
        try:
            test_output, _ = test_process.communicate(test_input, TEST_TIMEOUT_IN_SECONDS)
            test_exit_code = test_process.returncode
        except TimeoutExpired:
            test_process.kill()
            test_timeout = True
        # Check result
        test_passed = (not test_timeout) and \
                      test_exit_code == expected_exit_code % 256 and \
                      test_output == expected_output
        if test_passed:
            passed_count += 1
        else:
            failed_count += 1
        # Print CSV result line to stdout
        print("{:<12} {:<10} {:<6} {:<8} {}".format(test_name.upper() + ",",
                                              test_name.split("-")[0].upper() + ",",
                                              "Pass," if test_passed else "Fail,",
                                              choice(AUTHORS) + ",",
                                              description))
        # Print error messages to stderr
        if not test_passed:
            print_err("Failed test: {}: {}".format(test_name.upper(), description))
            if test_timeout:
                print_err("Reason: Timeout after {} seconds".format(TEST_TIMEOUT_IN_SECONDS))
            elif test_exit_code != expected_exit_code:
                print_err("Reason: Expected exit code {} but got {}".format(str(expected_exit_code),
                                                                            str(test_exit_code)))
            elif test_output != expected_output:
                print_err("Reason: Expected output \"{}\" but got \"{}\"".format("".join(map(chr, expected_output)),
                                                                                 "".join(map(chr, test_output))))
# Print summary to stderr
summary = []
print_msg("{} test{} passed".format(str(passed_count), "" if passed_count == 1 else "s"))
if failed_count > 0:
    print_err("{} test{} failed".format(str(failed_count), "" if failed_count == 1 else "s"))
if skipped_count > 0:
    print_err("{} test{} skipped".format(str(skipped_count), "" if skipped_count == 1 else "s"))
