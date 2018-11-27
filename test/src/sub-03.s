# exit code: -10
# description: Overflow when subtracting a very positive number from a very negative number

       .globl entry

entry:
        li $t1, 0x80000001
        li $t3, 0x7FFFFFFF
        sub $v0, $t1, $t3
        jr $zero
