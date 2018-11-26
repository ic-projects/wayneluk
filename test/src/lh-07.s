# exit code: 8
# description: Loading a halfword at address 0x10000002 should return 0x0008

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000002
        lh $v0, 0($t2)
        jr $zero
