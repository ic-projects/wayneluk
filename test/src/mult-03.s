# exit code: 4089934592
# description: Mult -300000000 and 15 returns 4089934592 in the LOW register

        .globl entry

entry:
        li $t1, -300000000
        li $t2, 0xF
        mult $t1, $t2
        mflo $v0
        jr $zero
