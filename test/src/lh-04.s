# exit code: -11
# description: Loading a halfword at address 0x24000007 should throw a memory misalignment error

        .globl entry

entry:
        li $t1, 0x24000007
        lh $t0, 0($t1)
        jr $zero
