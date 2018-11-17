# exit code: 100
# description: Return the value stored in the LOW register

        .globl entry

entry:
        li $t1, 100
        mtlo $t1
        mflo $v0
        jr $zero
