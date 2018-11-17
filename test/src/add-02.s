# exit code: -35
# description: Add two negative numbers -10 and -25 returns -35
        .globl entry

entry:
        addi $t0, $0, -10
        addi $t1, $0, -25
        add $v0, $t1, $t0
        jr $0
