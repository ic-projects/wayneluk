# exit code: -1
# description: (Implementation dependant) Reading EOF from halfword ADDR_GETC should return -1

       .globl entry

entry:
        li $t1, 0x30000000
        lh $v0, 0($t1)
        jr $zero
