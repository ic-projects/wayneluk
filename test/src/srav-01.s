# exit code: 7
# description: shift right by 5

       .globl entry

entry:
        li $t1, 15
        li $t3,  1
        srav $v0, $t1, $t3
        jr $zero
