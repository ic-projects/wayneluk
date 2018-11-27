# exit code: 1
# description: If unsigned value -2 is less than immediate unsigned value -1 should return 1

       .globl entry

entry:
        li $t1, -2
        sltiu $v0, $t1, -1
        jr $zero
