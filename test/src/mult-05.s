# exit code: 0
# description: Mult 0xFEDCBA98 and 0x0 returns 0 in the HIGH register

        .globl entry

entry:
        li $t1, 0xFEDCBA98
        li $t2, 0x0
        mult $t1, $t2
        mfhi $v0
        jr $zero
