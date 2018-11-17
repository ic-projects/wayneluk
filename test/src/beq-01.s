# exit code: 2
# description: Branch on equal

        .globl entry

entry:
        addiu $v0, $0, 0
        beq $0, $0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
