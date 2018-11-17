# exit code: 2
# description: Branch when less than 0

        .globl entry

entry:
        addiu $t0, $0, -10
        bltz $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
