# exit code: 15
# description: ANDI 0xFFFF and 0xF should return 0xF

        .globl entry

entry:
        li $t1, 0xFFFF
        and $v0, $t1, 0xF
        jr $zero
