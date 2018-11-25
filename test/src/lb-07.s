# exit code: 9
# description: Loading a byte at address 0x10000001 should return 0x09

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000001
        lb $v0, 0($t2)
        jr $zero
