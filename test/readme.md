# MIPS Testbench

## Add a test

Create a `.c` or `.s` file in the `src` directory.

The first two lines of a C source file should read:
```
// exit code: <EXPECTED EXIT CODE>
// description: <SHORT DESCRIPTION FOR THIS TEST>
```
or, for an assembly source file:
```
# exit code: <EXPECTED EXIT CODE>
# description: <SHORT DESCRIPTION FOR THIS TEST>
```

* If you want to provide a default input, provide a `.in` file with the same prefix as the source.
* If you expect the test to output something to STDOUT, provide the expected output
in a `.out` file with the same prefix as the source.

The testbench will automatically pick up any new tests.

## Remove a test

Just delete its source from the `src` directory.

## Other notes

* The testbench uses the Makefile in the project root directory to create its binaries.
  You can use this Makefile to manually check the test binaries.
* Tests have a 10 second timeout, so don't write long tests!
