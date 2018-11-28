# exit code: -11
# description: Load word left at address 0x11000002 should throw a memory error

        .globl entry

entry:
        li $t1, 0x11000000
        lwl $t0, 2($t1)
        jr $zero
