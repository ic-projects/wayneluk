# exit code: 3
# description: Branch if 0 is greater than 0 should exit with code 3

        .globl entry

entry:
        addiu $t0, $0, 0
        bgtz $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
