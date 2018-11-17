# exit code: 5
# description: Shift right by 0 should not modify the number

       .globl entry

entry:
        li $t1, 5
        li $t3,  0
        srlv $v0, $t1, $t3
        jr $zero
