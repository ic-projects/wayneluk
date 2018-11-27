# exit code: 0
# description: If 35 < 35 return 0

       .globl entry

entry:
        li $t1, 35
        sltu $v0, $t1, $t1
        jr $zero
