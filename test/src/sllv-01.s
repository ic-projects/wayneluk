# exit code: 14
# description: shift left 7 by shift value 1

       .globl entry

entry:
        li $t1, 7
        li $t2, 1
        sllv $v0, $t1, $t2
        jr $zero
