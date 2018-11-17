# exit code: 3
# description: no branching if 0 is less than 0

        .globl entry

entry:
        addi $t0, $0, 0
        bltz $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
