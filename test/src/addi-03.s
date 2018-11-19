# exit code: -100
# description: Adding -50 to -50 should return -100

        .globl entry

entry:
        addi $t0, $0, -50
        addi $v0, $t0, -50
        jr $zero
