# exit code: -10
# description: Overflow error test on the add function
        .globl main

main:
        lui $t0, 6
        lui $t1, 4294967295
        add $t0, $t1, $t0
