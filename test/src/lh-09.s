# exit code: -11
# description: Loading a halfword with negative offset at address 0x10000001 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000002
        lh $v0, -1($t2)
        jr $zero
