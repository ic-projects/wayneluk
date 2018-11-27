# exit code: -11
# description: Loading a byte at address 0x24000007 should throw a memory error

        .globl entry

entry:
        li $t1, 0x24000007
        lbu $t0, 0($t1)
        jr $zero
