# exit code: 0
# description: (Impementation specific) Reading 'a' from halfword ADDR_GETC should return 0

       .globl entry

entry:
        li $t1, 0x30000000
        lh $t0, 0($t1)
        jr $zero
