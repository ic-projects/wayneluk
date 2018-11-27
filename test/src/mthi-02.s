# exit code: -200
# description: Store the value 200 into the HIGH register

        .globl entry

entry:
        li $t1, -200
        mthi $t1
        mfhi $v0
        jr $zero
