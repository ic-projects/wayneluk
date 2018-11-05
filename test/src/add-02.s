# exit code: 0
# description: add two negative numbers
        .globl entry

entry:
        addi $t0, $0, -10
        addi $t1, $0, -25
        add $t2, $t1, $t0
