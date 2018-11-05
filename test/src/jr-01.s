# exit code: 1
# description: Jumping to 0 should exit gracefully

       .globl entry

entry:
        li $v0, 1
        jr $zero
        li $v0, 2
        jr $zero
