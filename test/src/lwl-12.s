# exit code: 220
# description: Loading a word left with offset of 0 should return 0xDCBA98AB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 1($t1)
        srl $v0, 24
        jr $zero
