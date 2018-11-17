# exit code: 4294967281
# description: Multu 0xFFFFFFFF and 0xF returns 4294967281 in the LOW register

        .globl entry

entry:
        li $t1, 0xFFFFFFFF
        li $t2, 0xF
        multu $t1, $t2
        mflo $v0
        jr $zero
