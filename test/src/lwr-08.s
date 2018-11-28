# exit code: -11
# description: Load word right at address 0x24000008 should throw a memory error

        .globl entry

entry:
        li $t1, 0x24000008
        lwr $t0, 0($t1)
        jr $zero
