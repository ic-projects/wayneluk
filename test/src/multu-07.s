# exit code: 16
# description: Square the number 0x403E9 returns 0x10 in the HIGH register

        .globl entry

entry:
        li $t1, 0x403E9
        multu $t1, $t1
        mfhi $v0
        jr $zero
