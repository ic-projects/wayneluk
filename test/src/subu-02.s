# exit code: -5
# description: subtract 20 from 15 should return -5

       .globl entry

entry:
        li $t1, 15
        li $t3,  20
        sub $v0, $t1, $t3
        jr $zero
