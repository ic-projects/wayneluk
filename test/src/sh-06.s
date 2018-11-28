# exit code: -11
# description: Storing a byte at 0x23999999 should result in a Memory Error exception

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x24000000
       sh $t1, -1($t2)
       jr $zero
