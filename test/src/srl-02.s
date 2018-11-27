# exit code: 254
# description: Shift right by 0 should not shift the value

       .globl entry

entry:
        li $t1, 0xFFFE
        srl $v0, $t1, 0
        jr $zero
