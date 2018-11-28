# exit code: 0
# description: Loading a word right with offset of 0 should return 0xABABAB00

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwr $v0, 0($t1)
        jr $zero
