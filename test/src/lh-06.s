# exit code: 8201
# description: Loading a halfowrd at address 0x10000000 should return 0x2009

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000000
        lh $v0, 0($t2)
        jr $zero
