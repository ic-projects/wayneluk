# exit code: 1
# description: shift value greater than 31 should only take the first 5 bits as the shift value

       .globl entry

entry:
        li $t1, 0xFFFF
        li $t3, 79
        srlv $v0, $t1, $t3
        jr $zero
