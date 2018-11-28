# exit code: 152
# description: Load word left with offset 2 stored at address 0x10000000 should return 0xBA98

       .globl entry

entry:
        addi $t0, $0, 0xBA98
        li $t1, 0x10000000
        lwl $v0, 2($t1)
        srl $v0, 16
        jr $zero
