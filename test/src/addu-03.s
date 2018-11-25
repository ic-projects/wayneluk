# exit code: -2
# description: Add a number to a very large number should not cause any overflow exception

        .globl entry

entry:
        li $t0, 0xFFFFFFFF
        li $t1, 0xFFFFFFFF
        addu $v0, $t0, $t1
        jr $zero
