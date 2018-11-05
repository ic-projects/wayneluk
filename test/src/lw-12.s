# exit code: 2
# description: Loading a word should return what was stored there

       .globl entry

entry:
        li $t0, 1
        sw $t0, 0x20000000($zero)
        li $t0, 2
        sw $t0, 0x20000004($zero)
        li $t0, 3
        sw $t0, 0x20000008($zero)
        li $t0, 0x20000004
        lw $v0, 0($t0)
        jr $zero
