# exit code: 2
# description: Branch if 10 is greater than 0 should exit with code 2

        .globl entry

entry:
        addiu $t0, $0, 10
        bgtz $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
