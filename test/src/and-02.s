# exit code: 20
# description: AND the same number should return the same number

        .globl entry

entry:
        li $t1, 20
        and $v0, $t1, $t1
        jr $zero
