# exit code: 99
# description: Loading a word left with offset of 1 should return 0x000063AB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwl $v0, 1($t1)
        srl $v0, 8
        jr $zero
