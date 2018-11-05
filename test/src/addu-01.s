# exit code: 100
# description: Adding a number to itself should double the number

        .globl entry

entry:
        addiu $t0, $0, 50
        addu $v0, $t0, $t0
        jr $zero
