# exit code: 171
# description: Loading a word right with offset of 2 should return 0xAB000000

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwr $v0, 2($t1)
        srl $v0, 24
        jr $zero
