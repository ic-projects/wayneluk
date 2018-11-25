# exit code: -8
# description: Loading a byte at address 0x10000003 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, -8
        li $t0, 0x20000003
        sb $t1, 0($t0)
        lb $v0, 0($t0)
        jr $zero
