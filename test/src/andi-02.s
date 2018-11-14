# exit code: 40
# description: ANDI the same number should return the number

        .globl entry

entry:
        li $t1, 40
        and $v0, $t1, 40
        jr $zero
