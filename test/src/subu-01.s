# exit code: 5
# description: Subtract 5 from 10 should return 5

       .globl entry

entry:
        li $t1, 10
        li $t3,  5
        sub $v0, $t1, $t3
        jr $zero
