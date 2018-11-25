# exit code: 0
# description: AND 0 and 0 should return 0

        .globl entry

entry:
        li $t1, 0x0
        li $t2, 0x0
        and $v0, $t1, $t2
        jr $zero
