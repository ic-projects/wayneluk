# exit code: 3
# description: no Branch when not equal

        .globl entry

entry:
        addiu $t0, $0, 5
        beq $0, $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
