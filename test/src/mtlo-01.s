# exit code: 5
# description: Stored the value 5 into the LOW register

        .globl entry

entry:
        li $t1, 5
        mtlo $t1
        mflo $v0
        jr $zero
