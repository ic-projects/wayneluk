# exit code: 99
# description: Loading a word right with offset of 3 should return 0x00000063

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwr $v0, 3($t1)
        jr $zero
