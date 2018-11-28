# exit code: -11
# description: Loading a halfword at address 0x11000000 should throw a memory error

        .globl entry

entry:
        li $t1, 0x11000000
        lhu $t0, 0($t1)
        jr $zero
