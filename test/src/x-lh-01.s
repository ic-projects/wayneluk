# exit code: 97
# description: (Implementation dependant) Reading 'a' from halfword ADDR_GETC + 2 should return 97

       .globl entry

entry:
        li $t1, 0x30000002
        lh $t0, 0($t1)
        jr $zero
