# exit code: 32
# description: Loading a bytes at addresses 0x10000003 to 0x0x10000000 should return 0x08000920

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
