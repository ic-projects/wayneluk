# exit code: 0
# description: (Implementation dependant) Storing 'c' to halfword ADDR_PUTC + 1 should return null

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000005
       sb $t1, 0($t2)
       jr $zero
