# exit code: 32
# description: Loading a bytes from addresses 0x10000003 to 0x10000000 should return 0x08000920

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lbu $t3, 0($t2)
        sll $v0, $t3, 8
        lbu $t3, -1($t2)
        or $v0, $v0, $t3
        sll $v0, $v0, 8
        lbu $t3, -2($t2)
        or $v0, $v0, $t3
        sll $v0, $v0, 8
        lbu $t3, -3($t2)
        or $v0, $v0, $t3
        jr $zero
