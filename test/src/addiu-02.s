# exit code: -100
# description: Add two negative numbers

        .globl entry

entry:
        addiu $t0, $0, -50
        addiu $v0, $t0, -50
        jr $zero
