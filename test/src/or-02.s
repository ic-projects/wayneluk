# exit code: 20
# description: OR the same number should return the same number

        .globl entry

entry:
        li $t1, 20
        li $t2, 20
        or $v0, $t1, $t2
        jr $zero
