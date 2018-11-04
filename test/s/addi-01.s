# exit code: 10
# description: Test the functionality  of addi instruction

        .globl main

main:
        lui $t3, 10
        addi $t1, $t3, -10