# exit code: 140737488322560
# description: Shift left 0xFFFFFFFF by shift value 15

       .globl entry

entry:
        li $t1, 0xFFFFFFFF
        li $t2, 0xF
        sllv $v0, $t1, $t2
        jr $zero
