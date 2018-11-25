# exit code: 15
# description: ANDI the same number should return the number

        .globl entry

entry:
        li $t1, 0xFFFF
        and $v0, $t1, 0xF
        jr $zero
