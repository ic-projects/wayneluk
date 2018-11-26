# exit code: 65244
# description: Loading a word right with offset of 1 should return 0x0000FEDC

       .globl entry

entry:
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwr $v0, 1($t1)
        jr $zero
