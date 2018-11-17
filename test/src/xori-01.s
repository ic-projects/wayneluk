# exit code: 4294901760
# description: Xoring 0xFFFFFFFF and 0xFFFF should return 0xFFFF0000

        .globl entry

entry:
        li $t1, 0xFFFFFFFF
        xori $v0, $t1, 0xFFFF
        jr $zero
