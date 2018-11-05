# exit code: 0
# description: add a positive number and a negative number
        .data

        .text
        .globl entry

entry:
        addi $t0, $0, -10
        addi $t1, $0, 50
        add $t2, $t1, $t0
