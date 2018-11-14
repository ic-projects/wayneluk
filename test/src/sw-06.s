# exit code: -11
# description: Storing 'c' to address 0x200000001 should throw a mis-alligned memory error

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x20000001
       sw $t1, 0($t2)
       jr $zero
