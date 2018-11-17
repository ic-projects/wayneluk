# exit code: 2
# description: Branch when greater than or equal to 0

        .globl entry

entry:
        addiu $t0, $0, 10
        bgez $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
