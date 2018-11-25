# exit code: 99
# description: Storing 'c' to address 0x20000008 should store the value at that address

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x20000008
       sw $t1, -4($t2)
       lw $v0, -4($t2)
       jr $zero
