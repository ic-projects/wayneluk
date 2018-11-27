# exit code: 1
# description: If 35 is less than 40 return 1

       .globl entry

entry:
        li $t1, 35
        li $t2, 40
        sltu $v0, $t1, $t2
        jr $zero
