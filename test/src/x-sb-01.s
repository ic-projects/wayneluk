# exit code: 0
# description: (Implementation dependant) Storing 'c' to halfword ADDR_PUTC + 3 should return 'c'

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000007
       sb $t1, 0($t2)
       jr $zero
