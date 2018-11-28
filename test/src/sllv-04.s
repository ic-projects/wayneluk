# exit code: 48
# description: Shift value greater than 31 should only take the first 5 bits as the shift value

       .globl entry

entry:
        li $t1, 0xFEDCBA98
        li $t2, 33
        sllv $v0, $t1, $t2
        jr $zero
