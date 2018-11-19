# exit code: -10
# description: Adding two very positive numbers should cause an Integer Overflow exception

        .globl entry

entry:
        li $t0, 2147483647
        addi $v0, $t0, 1
        jr $zero
