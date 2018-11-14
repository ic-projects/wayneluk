# exit code: -50
# description: mult -5 and 10 returns -50

        .globl entry

entry:
        li $t1, -5
        li $t2, 10
        multu $t1, $t2
        mflo $v0
        jr $zero
