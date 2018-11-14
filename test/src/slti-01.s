# exit code: 1
# description: -5 less than immediate value -3 return 1

       .globl entry

entry:
        li $t1, -5
        slti $v0, $t1, -3
        jr $zero
