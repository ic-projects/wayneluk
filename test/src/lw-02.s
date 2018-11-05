# exit code: -1
# description: (Implementation specifc) Reading EOF from word ADDR_GETC should return -1

       .globl entry

entry:
        li $t1, 0x30000000
        lw $v0, 0($t1)
        jr $zero
