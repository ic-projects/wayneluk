# exit code: 9
# description: Loading a byte at address 0x10000003 should throw a memory error

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000002
        lhu $t3, 0($t2)
        sll $v0, $t3, 16
        lhu $t3, -2($t2)
        or $v0, $v0, $t3
        jr $zero
