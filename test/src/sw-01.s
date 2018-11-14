# exit code: 0
# description: Storing 'c' to word ADDR_PUTC should print 'c' to stdout

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000004
       sw $t1, 0($t2)
       jr $zero
