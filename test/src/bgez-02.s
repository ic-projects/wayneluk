# exit code: 3
# description: no branching when not greater than or equal to 0

        .globl entry

entry:
        addi $t0, $0, -5
        bgez $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
