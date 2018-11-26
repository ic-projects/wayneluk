# exit code: -8
# description: Shift right by 33

       .globl entry

entry:
        li $t1, -15
        li $t3,  33
        srav $v0, $t1, $t3
        jr $zero
