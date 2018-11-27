# exit code: 60
# description: Shift the value 15 left by -254 should return 60

       .globl entry

entry:
        li $t1, 15
        li $t3,  -254
        sllv $v0, $t1, $t3
        jr $zero
