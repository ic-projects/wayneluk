# exit code: -1
# description: Signed division of -9 by 2 should return -1 in the HI register

        .globl entry

entry:
        addi $t0, $0, -9
        addi $t1, $0, 2
        div $t0, $t1
        mfhi $v0
        jr $zero
