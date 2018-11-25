# exit code: 3
# description: Branch not equal

        .globl entry

entry:
        addiu $v0, $0, 0
        bne $0, $0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
