# exit code: -11
# description: Storing 'c' to missalligned memory ADDR_PUTC + 1 should throw a memory misallignment error

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000005
       sw $t1, 0($t2)
       jr $zero
