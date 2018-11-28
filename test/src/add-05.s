# exit code: -10
# description: Adding two very negative numbers should return an Integer Overflow excpetion

        .globl entry

entry:
        li $t0, -2147483632
        li $t1, -2147483647
        add $v0, $t0, $t1
        jr $zero
