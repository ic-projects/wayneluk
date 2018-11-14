# exit code: -1056
# description: shift left -33 by shift value 5

       .globl entry

entry:
        li $t1, -33
        li $t2, 5
        sllv $v0, $t1, $t2
        jr $zero
