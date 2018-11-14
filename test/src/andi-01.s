# exit code: 0
# description: ANDI 0xFFFF and 0x0000 should return 0

        .globl entry

entry:
        li $t1, 0xFFFF
        andi $v0, $t1, 0
        jr $zero
