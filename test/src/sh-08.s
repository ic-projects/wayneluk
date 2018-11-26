# exit code: -11
# description: Storing 'c' to halfword ADDR_PUTC + 3 should throw a misaligned memory error

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000007
       sh $t1, 0($t2)
       jr $zero
