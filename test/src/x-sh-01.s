# exit code: 0
# description: (Implementation dependant) Storing 'c' to halfword ADDR_PUTC + 2 should print c to stdout

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000006
       sh $t1, 0($t2)
       jr $zero
