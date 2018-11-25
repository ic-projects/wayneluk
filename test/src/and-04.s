# exit code: 65535
# description: AND 0xFFFF and 0xFFFF should return 0

        .globl entry

entry:
        li $t1, 0xFFFF
        li $t2, 0xFFFF
        and $v0, $t1, $t2
        jr $zero
