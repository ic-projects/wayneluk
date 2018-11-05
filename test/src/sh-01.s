# exit code: 0
# description: (Implementation dependant) Storing 'c' to byte ADDR_PUTC + 2 should print c to standard out
      .globl entry
entry:
       li $t1, 99
       li $t2, 0x30000006
       sh $t1, 0($t2)
       jr $zero
