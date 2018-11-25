# exit code: 0
# description: Loading a byte at address 0x30000008 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000002
        lbu $v0, 0($t2)
        jr $zero
