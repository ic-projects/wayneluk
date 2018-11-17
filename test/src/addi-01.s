# exit code: 10
# description: Add immediate value 10 to 0 should return 10
        .globl entry

entry:
        addi $v0, $0, 10
        jr $zero

