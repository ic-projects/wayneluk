# exit code: 0
# description: If 4294967295 < 4294967294 return 0

       .globl entry

entry:
        li $t1, 0xFFFFFFFF
        li $t2, 0xFFFFFFFE
        sltu $v0, $t1, $t2
        jr $zero
