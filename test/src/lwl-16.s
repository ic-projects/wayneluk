# exit code: 99
# description: Loading a word left with offset of 3 should return 0x63ABABAB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t1, 0x30000000
        lwl $v0, 3($t1)
        srl $v0, 24
        jr $zero
