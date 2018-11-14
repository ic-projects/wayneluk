# exit code: -10
# description: Overflow

       .globl entry

entry:
        li $t1, -2147483647
        li $t3,  0x7FFFFFFF
        sub $v0, $t1, $t3
        jr $zero
