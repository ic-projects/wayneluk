# exit code: 376
# description: Storing a byte at 0x23999998 should be valid

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x24000000
       sh $t1, -2($t2)
       lw $t0, -4($t2)
       lw $t1, -4($t2)
       srl $t1, $t1, 8
       add $v0, $t0, $t1
       jr $zero
