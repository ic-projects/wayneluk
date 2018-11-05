# exit code: 97
# description: (Implementation specifc) Reading 'a' from word ADDR_GETC should return 97

       .globl entry

entry:
        li $t1, 0x30000000
        lw $v0, 0($t1)
        jr $zero
