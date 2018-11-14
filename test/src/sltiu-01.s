# exit code: 1
# description: 100 is less than immediate value 150 returns 1

       .globl entry

entry:
        li $t1, 100
        sltiu $v0, $t1, 150
        jr $zero
