# exit code: -11
# description: Storing 'c' to halfword ADDR_PUTC + 1 should throw a misalligned memory error

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000005
       sh $t1, 0($t2)
       jr $zero
