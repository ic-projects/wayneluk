# exit code: 255
# description: Xoring 0 and 255 should return 255

        .globl entry

entry:
        li $t1, 0x00
        li $t2, 0xFF
        xor $v0, $t1, $t2
        jr $zero
