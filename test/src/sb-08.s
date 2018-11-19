# exit code: 603599443
# description: Should be able to store a word byte-by-byte

        .globl entry

entry:
        li $t0, 0x00000012
        li $t1, 0x00000034
        li $t2, 0x000000AB
        li $t3, 0x000000CD
        li $t4, 0x23FA3250
        sb $t0, -4($t4)
        sb $t1, -3($t4)
        sb $t2, -2($t4)
        sb $t3, -1($t4)
        sb $t0, 0($t4)
        sb $t1, 1($t4)
        sb $t2, 2($t4)
        sb $t2, 3($t4)
        sub $t3, $t4, 4
loop:
        addi $t3, $t3, 1
        addi $t4, $t4, 1
        lb $t1, 0($t3)
        lb $t2, 0($t4)
        bne $t1, $t2, fail
        j loop
fail:
        add $v0, $t4, $zero
        jr $zero
