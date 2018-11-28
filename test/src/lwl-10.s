# exit code: 186
# description: Loading a word left with offset of 2 should return 0xBA98ABAB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 2($t1)
        srl $v0, 24
        jr $zero
