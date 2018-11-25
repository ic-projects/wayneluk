# exit code: 3
# description: Branch when greater than or equal to 0 with negative offset

        .globl entry

entry:
        beq $0, $0, jump
jump_up:
        addiu $v0, $v0, 1
        jr $31
jump:
        addiu $t0, $0, 10
        bgezal $t0, jump_up
        addiu $v0, $v0, 2
        jr $zero
