# exit code: 0
# description: Loading a byte with negative offset at address 0x10000002 should return 0

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lb $v0, -1($t2)
        jr $zero
