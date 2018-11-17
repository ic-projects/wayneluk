# exit code: -2
# description: Shift right by 5

       .globl entry

entry:
        li $t1, -0xFFFF
        srl $v0, $t1, 0xF
        jr $zero
