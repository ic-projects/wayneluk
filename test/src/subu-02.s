# exit code: -5
# description: Subtract 20 from 15 should return -5

       .globl entry

entry:
        li $t1, 15
        li $t3,  20
        subu $v0, $t1, $t3
        jr $zero
