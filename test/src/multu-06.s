# exit code: 525814289
# description: Square the number 0x403E9 returns 0x1F574A11 in the LO register

        .globl entry

entry:
        li $t1, 0x403E9
        multu $t1, $t1
        mflo $v0
        jr $zero
