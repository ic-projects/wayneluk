# exit code: 99
# description: Loading a word left with offset of 2 should return 0x0063ABAB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwl $v0, 2($t1)
        srl $v0, 16
        jr $zero
