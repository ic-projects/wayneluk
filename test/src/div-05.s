# exit code: -10
# description: Signed division of 10 by -1 should return -10 in the LO register

        .globl entry

entry:
        addi $t0, $0, 10
        addi $t1, $0, -1
        div $t0, $t1
        mflo $v0
        jr $zero
