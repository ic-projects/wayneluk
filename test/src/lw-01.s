# exit code: 97
# description: Reading 'a' from word ADDR_GETC should return 97

       .globl entry

entry:
        li $t1, 0x30000000
        lw $v0, 0($t1)
        jr $zero
