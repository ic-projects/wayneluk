# exit code: -4
# description: Signed division of 9 by -2 should return -4 in the LO register

        .globl entry

entry:
        addi $t0, $0, 9
        addi $t1, $0, -2
        div $t0, $t1
        mflo $v0
        jr $zero
