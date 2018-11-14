# exit code: -15
# description: subtract 20 from 5 returns -15

       .globl entry

entry:
        li $t1, 5
        li $t2, 20
        sub $v0, $t1, $t2
        jr $zero
