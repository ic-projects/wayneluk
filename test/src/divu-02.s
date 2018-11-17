# exit code: 0
# description: Dividing 30 by 5 should return 0 in the HI register

        .globl entry

entry:
        addi $t0, $0, 30
        addi $t1, $0, 5
        divu $t0, $t1
        mfhi $v0
        jr $zero
