# exit code: 14
# description: multu 0xFFFFFFFF and 0xF returns 14 in the HIGH register

        .globl entry

entry:
        li $t1, 0xFFFFFFFF
        li $t2, 0xF
        multu $t1, $t2
        mfhi $v0
        jr $zero
