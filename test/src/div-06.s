# exit code: 0
# description: Signed division of 10 by -1 should return 0 in the HI register

        .globl entry

entry:
        addi $t0, $0, 10
        addi $t1, $0, -1
        div $t0, $t1
        mfhi $v0
        jr $zero
