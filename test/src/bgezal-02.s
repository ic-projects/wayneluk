# exit code: 1
# description: No branching when less than 0

        .globl entry

entry:
        addi $t0, $0, -10
        bgezal $t0, jump
        addiu $v0, $v0, 1
        jr $zero
jump:
        addiu $v0, $v0, 2
        jr $31
