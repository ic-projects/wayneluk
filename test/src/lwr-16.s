# exit code: 171
# description: Loading a word right with offset of 1 should return 0xABAB0000

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwr $v0, 1($t1)
        srl $v0, 16
        jr $zero
