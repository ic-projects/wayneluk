# exit code: 2550136832
# description: Loading a word with negative offset should return what was stored there

       .globl entry

entry:
        li $t0, 0xFEDCBA98
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 3($t1)
        jr $zero