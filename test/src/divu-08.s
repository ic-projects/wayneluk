# exit code: 1
# description: Unsigned division of -1 by -2 should return 1 in the HI register

        .globl entry

entry:
        addi $t0, $0, -1
        addi $t1, $0, -2
        divu $t0, $t1
        mfhi $v0
        jr $zero
