# exit code: 5
# description: Jumping to to entry should return to the beginning of the program

       .globl entry

entry:
        addi $v0, $v0, 1
        li $t0, 5
        beq $v0, $t0, exit
        j entry
exit:
        jr $zero
