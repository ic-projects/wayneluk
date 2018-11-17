# exit code: 6
# description: Dividing 34 by 5 should return 6 in the LO register

        .globl entry

entry:
        addi $t0, $0, 30
        addi $t1, $0, 5
        divu $t0, $t1
        mflo $v0
        jr $zero
