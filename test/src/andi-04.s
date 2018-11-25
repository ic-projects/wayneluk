# exit code: 65535
# description: ANDI the same number should return the number

        .globl entry

entry:
        li $t1, 0xFFFF
        and $v0, $t1, 0xFFFF
        jr $zero
