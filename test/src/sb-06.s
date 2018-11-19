# exit code: 205
# description: Storing a byte at 0x23999999 should be valid

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x24000000
       sb $t1, -1($t2)
       lw $v0, -4($t2)
       jr $zero
