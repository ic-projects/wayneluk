# exit code: 8
# description: Loading a byte at address 0x20000002 should returning what was stored there

        .globl entry

entry:
        addi $t1, $0, 8
        li $t0, 0x20000002
        sb $t1, 0($t0)
        lbu $v0, 0($t0)
        jr $zero
