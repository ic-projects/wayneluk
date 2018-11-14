# exit code: 20
# description: return the value stored in the HIGH register

        .globl entry

entry:
        li $t1, 20
        mthi $t1
        mfhi $v0
        jr $zero
