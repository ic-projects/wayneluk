# exit code: -8
# description: Loading a halfword at address 0x20000003 should returning what was stored there

        .globl entry

entry:
        addi $t1, $0, -8
        li $t0, 0x20000002
        sh $t1, 0($t0)
        lh $v0, 0($t0)
        jr $zero
