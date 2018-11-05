# exit code: 0
# description: (Implementation specifc) Reading 'a' from byte ADDR_GETC should return 0

       .globl entry

entry:
        li $t1, 0x30000000
        lb $v0, 0($t1)
        jr $zero
