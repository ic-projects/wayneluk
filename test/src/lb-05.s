# exit code: -11
# description: Loading a byte at address 0x30000008 should throw a memory error

        .globl entry

entry:
        li $t1, 0x30000008
        lb $t0, 0($t1)
        jr $zero
