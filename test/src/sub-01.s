# exit code: 15
# description: subtract 20 from 35 returns 15

       .globl entry

entry:
        li $t1, 35
        li $t2, 20
        sub $v0, $t1, $t2
        jr $zero
