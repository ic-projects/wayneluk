# exit code: 15
# description: Xoring 0xF0 and 0xFF should return 0x0F

        .globl entry

entry:
        li $t1, 0xF0
        li $t2, 0xFF
        xor $v0, $t1, $t2
        jr $zero
