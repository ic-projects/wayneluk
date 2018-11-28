# exit code: 171
# description: Loading a word right with offset of 1 should return 0xABABFEDC and shift right by 16 should return 0xABAB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwr $v0, 1($t1)
        srl $v0, 16
        jr $zero
