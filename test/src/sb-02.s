# exit code: 205
# description: Storing a byte at 0x20000001 should be valid

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x20000000
       sb $t1, 1($t2)
       lw $v0, 0($t2)
       srl $v0, $v0, 16
       jr $zero
