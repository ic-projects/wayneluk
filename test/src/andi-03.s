# exit code: 0
# description: ANDI 0 and 0 should return 0

        .globl entry

entry:
        li $t1, 0x0000
        and $v0, $t1, 0
        jr $zero
