# exit code: 0
# description: (Implementation dependant) Storing 'c' to halfword ADDR_PUTC  should print null to stdout

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000004
       sh $t1, 0($t2)
       jr $zero
