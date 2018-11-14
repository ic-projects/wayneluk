# exit code: 99
# description: Storing 'c' to address 0x20000008 should store the value at that address

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x20000008
       sw $t1, 0($t2)
       lw $v0, 0x20000008
       jr $zero
