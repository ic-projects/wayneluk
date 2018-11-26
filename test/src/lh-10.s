# exit code: 8
# description: Loading a halfword with negative offset at address 0x10000002 should return 0x0008

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lh $v0, -1($t2)
        jr $zero
