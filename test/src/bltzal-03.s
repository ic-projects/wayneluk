# exit code: 3
# description: Branch when less than 0 with negative offset

        .globl entry

entry:
        beq $0, $0, jump
jump_up:
        addiu $v0, $v0, 1
        jr $31
jump:
        addi $t0, $0, -10
        bltzal $t0, jump_up
        addiu $v0, $v0, 2
        jr $zero
