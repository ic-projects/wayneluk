# exit code: 1
# description: Loading a word with negative offset should return what was stored there

       .globl entry

entry:
        li $t0, 1
        sw $t0, 0x20000000($zero)
        li $t0, 2
        sw $t0, 0x20000004($zero)
        li $t0, 3
        sw $t0, 0x20000008($zero)
        li $t0, 0x20000004
        lw $v0, -4($t0)
        jr $zero
