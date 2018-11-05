# exit code: -1
# description: (Implementation specifc) Reading EOF from byte ADDR_GETC should return -1

       .globl entry

entry:
        li $t1, 0x30000000
        lb $v0, 0($t1)
        jr $zero
