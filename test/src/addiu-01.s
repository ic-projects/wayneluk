# exit code: -50
# description: Add a negative number to zero should returns the negative number

        .globl entry

entry:
        addiu $v0, $0, -50
        jr $zero
