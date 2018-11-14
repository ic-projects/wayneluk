# exit code: 2147450880
# description: shift left by 15

       .globl entry

entry:
        li $t1, 0xFFFF
        sll $v0, $t1, 0xF
        jr $zero
