# exit code: 99
# description: Storing a value to address 0x20000004 should store the value at that address (negative offset)

      .globl entry

entry:
       li $t1, 99
       li $t2, 0x20000008
       sw $t1, -4($t2)
       lw $v0, -4($t2)
       jr $zero
