# exit code: 25
# description: mult 5 and 5 returns 25

        .globl entry

entry:
        li $t1, 5
        li $t2, 5
        mult $t1, $t2
        mflo $v0
        jr $zero
