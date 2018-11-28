# exit code: 0
# description: If 40 < 35 return 0

       .globl entry

entry:
        li $t1, 40
        li $t2, 35
        sltu $v0, $t1, $t2
        jr $zero
