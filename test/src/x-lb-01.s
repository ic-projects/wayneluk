# exit code: 97
# description: (Implementation dependant) Reading 'a' from byte ADDR_GETC + 3 should return 97

       .globl entry

entry:
        li $t1, 0x30000003
        lb $v0, 0($t1)
        jr $zero
