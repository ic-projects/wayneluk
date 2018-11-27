# exit code: 1
# description: Shift the value 0xFFFF right by 15 should return 1

       .globl entry

entry:
        li $t1, 0xFFFF
        srl $v0, $t1, 0xF
        jr $zero
