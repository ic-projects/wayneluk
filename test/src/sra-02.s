# exit code: -2
# description: Shift the value -65535 right by 15 should return -2

       .globl entry

entry:
        li $t1, 0xFFFF0001
        srl $v0, $t1, 0xF
        jr $zero
