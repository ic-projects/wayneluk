# exit code: -11
# description: Storing a value to missalligned memory ADDR_PUTC + 3 should throw a memory misalignment error

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000007
       sw $t1, 0($t2)
       jr $zero
