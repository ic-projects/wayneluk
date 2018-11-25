# exit code: 1
# description: Branch when less than or equal to 0

        .globl entry

entry:
        addiu $t0, $0, 10
        bltzal $t0, jump
        addiu $v0, $v0, 1
        jr $zero
jump:
        addiu $v0, $v0, 2
        jr $31
