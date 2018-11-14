# exit code: 0
# description: Add a negative number(-50) and a positive number (50) returns 0

        .globl entry

entry:
        addi $t0, $0, -50
        addi $v0, $t0, 50
        jr $zero
