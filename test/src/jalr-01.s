# exit code: 3
# description: JALR should store the next instruction to be executed

       .globl entry

entry:
        addi $v0, $v0, 1
        li $t1, 0x10000000
        bne $t2, $zero, exit
        jalr $t2, $t1
        addi $v0, $v0, 1
        jr $zero

exit:
        jr $t2
