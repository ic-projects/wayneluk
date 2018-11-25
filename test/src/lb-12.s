# exit code: 32
# description: Loading a byte at address 0x10000003 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lb $t3, 0($t2)
        sll $v0, $t3, 8
        lb $t3, -1($t2)
        or $v0, $v0, $t3
        sll $v0, $v0, 8
        lb $t3, -2($t2)
        or $v0, $v0, $t3
        sll $v0, $v0, 8
        lb $t3, -3($t2)
        or $v0, $v0, $t3
        jr $zero
