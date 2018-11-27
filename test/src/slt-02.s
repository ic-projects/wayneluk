# exit code: 0
# description: 5 less than -5 return 0

       .globl entry

entry:
        li $t1, 5
        li $t2, -5
        slt $v0, $t1, $t2
        jr $zero
