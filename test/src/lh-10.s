# exit code: 8
# description: Loading a byte at address 0x30000008 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lh $v0, -1($t2)
        jr $zero
