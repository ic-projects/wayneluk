# exit code: 152
# description: Load word right with offset 3 stored at address 0x10000000 should return 0x2008BA98

       .globl entry

entry:
        addi $t0, $0, 0xBA98
        li $t1, 0x10000000
        lwr $v0, 3($t1)
        jr $zero
