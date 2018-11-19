# exit code: 205
# description: Storing a byte at 0x20000003 should be valid

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x20000000
       sb $t1, 3($t2)
       lw $v0, 0($t2)
       jr $zero
