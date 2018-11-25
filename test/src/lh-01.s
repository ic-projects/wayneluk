# exit code: -11
# description: Loading halfword at address 0x0 should throw a memory error

        .globl entry

entry:
        li $t1, 0x0
        lh $t0, 0($t1)
