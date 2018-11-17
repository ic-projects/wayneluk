# exit code: 4294967294
# description: Multu -300000000 and 15 returns 4294967294 in the HIGH register

        .globl entry

entry:
        li $t1, -300000000
        li $t2, 0xF
        mult $t1, $t2
        mfhi $v0
        jr $zero
