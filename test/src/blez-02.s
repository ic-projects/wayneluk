# exit code: 3
# description: No branching if greater than to 0

        .globl entry

entry:
        addi $t0, $0, 5
        blez $t0, jump
        addiu $v0, $0, 1
jump:
        addiu $v0, $v0, 2
        jr $zero
