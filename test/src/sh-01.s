# exit code: 0
# description: Implementation specific lb IO
      .globl entry
entry:
       li $t1, 99
       li $t2, 0x30000006
       sh $t1, 0($t2)
       nop
       jr $zero
