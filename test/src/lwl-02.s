# exit code: 4293918464
# description: Loading a word left with offset of 1 should return 0xFFEFFF00

       .globl entry

entry:
        li $t0, 0xFFFFEFFF
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 1($t1)
        jr $zero
