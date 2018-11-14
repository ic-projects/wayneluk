# exit code: 9264751
# description: shift right by 5

       .globl entry

entry:
        li $t1, 296472047
        li $t3,  5
        srlv $v0, $t1, $t3
        jr $zero
