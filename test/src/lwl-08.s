# exit code: -11
# description: Load word left at address 0x24000008 should throw a memory error

        .globl entry

entry:
        li $t1, 0x24000008
        lwl $t0, 0($t1)
        jr $zero
