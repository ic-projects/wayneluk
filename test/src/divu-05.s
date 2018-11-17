# exit code: 0
# description: Unsigned division of 10 by -1 should return 0 in the LO register

        .globl entry

entry:
        addi $t0, $0, 10
        addi $t1, $0, -1
        divu $t0, $t1
        mflo $v0
        jr $zero
