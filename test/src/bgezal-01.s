# exit code: 3
# description: Branch when greater than or equal to 0

        .globl entry

entry:
        addiu $t0, $0, 10
        bgezal $t0, jump
        addiu $v0, $v0, 1
        jr $zero
jump:
        addiu $v0, $v0, 2
        jr $31
