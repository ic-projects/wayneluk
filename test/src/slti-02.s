# exit code: 0
# description: 3 less than -5 should return 0

       .globl entry

entry:
        li $t1, 3
        slti $v0, $t1, -5
        jr $zero
