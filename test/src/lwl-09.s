# exit code: 171
# description: Loading a word left with offset of 3 should return 0x98ABABAB

       .globl entry

entry:
        li $v0, 0xABABABAB
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 3($t1)
        jr $zero
