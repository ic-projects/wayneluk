# exit code: -1
# description: (Impementation specific) Reading EOF from halfword ADDR_GETC should return -1

       .globl entry

entry:
        li $t1, 0x30000000
        lh $t0, 0($t1)
        jr $zero
