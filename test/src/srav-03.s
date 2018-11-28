# exit code: 3
# description: Shift the value 15 right by -254 should return 3

       .globl entry

entry:
        li $t1, 15
        li $t3,  -254
        srav $v0, $t1, $t3
        jr $zero
