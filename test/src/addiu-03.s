# exit code: 2147483747
# description: Add a number to a very large number should not cause any overflow exception

        .globl entry

entry:
        li $t0, 0x7FFFFFFF
        addiu $v0, $t0, 0x0064
        jr $zero
