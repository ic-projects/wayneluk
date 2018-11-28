# exit code: -11
# description: Loading a byte at address 0x19999999 should throw a memory error

        .globl entry

entry:
        li $t1, 0x19999999
        lb $t0, 0($t1)
        jr $zero
