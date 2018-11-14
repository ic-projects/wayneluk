# exit code: 0
# description: AND 0xFFFF and 0x0000 should return 0

        .globl entry

entry:
        li $t1, 0xFFFF
        li $t2, 0x0
        and $v0, $t1, $t2
        jr $zero
