# exit code: -1
# description: Load word left with no missallignment stored at address 0x20000000 should return -1

       .globl entry

entry:
        li $t0, 0xFFFFFFFF
        li $t1, 0x20000000
        sw $t0, 0($t1)
        lwl $v0, 0($t1)
        jr $zero
