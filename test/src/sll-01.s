# exit code: 14
# description: Shift left by 1

       .globl entry

entry:
        li $t1, 7
        sll $v0, $t1, 1
        jr $zero
