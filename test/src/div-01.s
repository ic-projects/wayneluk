# exit code: 6
# description: Dividing 30 by 5 should return 6 in the LO register

        .globl entry

entry:
        addi $t0, $0, 30
        addi $t1, $0, 5
        div $t0, $t1
        mflo $v0
        jr $zero
