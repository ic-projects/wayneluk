# exit code: 5
# description: Jumping to address 0x10000000 should return to the beginning of the program

       .globl entry

entry:
        addi $v0, $v0, 1
        li $t0, 5
        beq $v0, $t0, exit
        li $t1, 0x10000000
        jr $t1
exit:
        jr $zero
