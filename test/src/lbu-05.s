# exit code: 60
# description: Loading a byte (with positive offset) at address 0x10000004 should return 0x3c

        .globl entry

entry:
        addi $t1, $0, 0x8
        li $t2, 0x10000003
        lbu $v0, 1($t2)
        jr $zero
