# exit code: 2550136832
# description: Loading a word with offset of 3 should return 0x98000000

       .globl entry

entry:
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 3($t1)
        jr $zero
