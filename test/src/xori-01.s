# exit code: 240
# description: Xoring 0xFF and 0xF should return 0xF0

        .globl entry

entry:
        li $t1, 0xFF
        xori $v0, $t1, 0xF
        jr $zero
