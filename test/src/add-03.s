# exit code: 40
# description: Add a positive number (50) and a negative number (-10) returns 40
        .globl entry

entry:
        addi $t0, $0, -10
        addi $t1, $0, 50
        add $v0, $t1, $t0
        jr $zero
