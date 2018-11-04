# exit code: -10
# description: Overflow checking of addi instruction

        .globl main

main:
        lui $t2, 100
        addi $t0, $t2, 2147483647
