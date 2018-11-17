# exit code: 0
# description: Dividing 34 by 5 should return 4 in the HI register

        .globl entry

entry:
        addi $t0, $0, 30
        addi $t1, $0, 5
        div $t0, $t1
        mfhi $v0
        jr $zero
