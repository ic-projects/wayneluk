# exit code: -10
# description: Adding two very positive numbers should return an Integer Overflow excpetion

        .globl entry

entry:
        li $t0, 1361266021
        li $t1, 786217627
        add $v0, $t0, $t1
        jr $zero
