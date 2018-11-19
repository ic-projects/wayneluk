# exit code: 5
# description: Should jump when not equal to 5

        .globl entry

entry:
        li $t0, 5
start:
        addiu $v0, $v0, 1
        bne $v0, $t0, start
        jr $zero
