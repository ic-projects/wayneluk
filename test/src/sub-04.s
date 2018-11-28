# exit code: -10
# description: Overflow error when subtracting a very negative number from a very positive number

       .globl entry

entry:
        li $t1, 0x7FFFFFFF
        li $t3, 0x80000001
        sub $v0, $t1, $t3
        jr $zero
