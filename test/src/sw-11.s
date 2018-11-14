# exit code: -11
# description: Storing 'c' to address 0x30000000 should throw a memory error - no write access

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x30000000
       sw $t1, 0($t2)
       jr $zero
