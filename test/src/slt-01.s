# exit code: 1
# description: -10 is less than -8 should return 1

       .globl entry

entry:
        li $t1, -10
        li $t2, -8
        slt $v0, $t1, $t2
        jr $zero
