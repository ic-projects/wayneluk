# exit code: 7
# description: Shift the value 15 right by 1 should return 7

       .globl entry

entry:
        li $t1, 15
        li $t3,  1
        srav $v0, $t1, $t3
        jr $zero
