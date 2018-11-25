# exit code: 65535
# description: ANDI 0xFFFF and 0xFFFF should return 0xFFFF (all 1s)

        .globl entry

entry:
        li $t1, 0xFFFF
        and $v0, $t1, 0xFFFF
        jr $zero
