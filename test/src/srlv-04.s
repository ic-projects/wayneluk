# exit code: 16383
# description: Shift right with a negative shift value should only shift using the last 5 bits

       .globl entry

entry:
        li $t1, 0xFFFF
        li $t3, -254
        srlv $v0, $t1, $t3
        jr $zero
