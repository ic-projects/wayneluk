# exit code: 376
# description: Storing a halfword at 0x20000000 should be valid

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x20000000
       sh $t1, 0($t2)
       lw $t0, 0($t2)
       srl $t0, $t0, 16
       lw $t1, 0($t2)
       srl $t1, $t1, 24
       add $v0, $t0, $t1
       jr $zero
