# exit code: 254
# description: Loading a word right with offset of 0 should return 0x000000FE

       .globl entry

entry:
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwr $v0, 0($t1)
        jr $zero
