# exit code: -2
# description: Subtract a very negative number from a very postive number should not result in an overflow error

       .globl entry

entry:
        li $t1, 0x7FFFFFFF
        li $t3, 0x80000001
        subu $v0, $t1, $t3
        jr $zero
