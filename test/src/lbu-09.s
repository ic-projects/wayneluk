# exit code: -11
# description: Loading a byte at address 0x0 should throw a memory error

        .globl entry

entry:
        li $t1, 0x0
        lbu $t0, 0($t1)
        jr $zero
