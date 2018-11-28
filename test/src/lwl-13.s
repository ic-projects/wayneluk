# exit code: 99
# description: Loading a word left with offset of 0 should return 0x00000063

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwl $v0, 0($t1)
        jr $zero
