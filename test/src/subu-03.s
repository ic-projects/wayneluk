# exit code: 2
# description: Subtract a very positive number from a very negative number should not result in an overflow error

       .globl entry

entry:
        li $t1, 0x80000001
        li $t3, 0x7FFFFFFF
        subu $v0, $t1, $t3
        jr $zero
