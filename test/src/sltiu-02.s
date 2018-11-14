# exit code: 0
# description: 100 is less than immediate value 75 should return 0

       .globl entry

entry:
        li $t1, 100
        sltiu $v0, $t1, 75
        jr $zero
