# exit code: -10
# description: Overflow

       .globl entry

entry:
        li $t1, 0x7FFFFFFF
        li $t3, -0x7FFFFFFF
        sub $v0, $t1, $t3
        jr $zero
