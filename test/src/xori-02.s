# exit code: 15
# description: Xoring 0 and 0 and 0xF should return 0xF

        .globl entry

entry:
        li $t1, 0x0
        xori $v0, $t1, 0x0
        xori $v0, $v0, 0xF
        jr $zero
