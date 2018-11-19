# exit code: -10
# description: Adding two very negative numbers should return an Integer Overflow excpetion

        .globl entry

entry:
        li $t0, -2147483648
        addi $v0, $t0, -1
        jr $zero
