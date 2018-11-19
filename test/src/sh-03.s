# exit code: -11
# description: Storing a byte at 0x20000001 should result in a Memory Error exception

      .globl entry

entry:
       li $t1, 0x1234ABCD
       li $t2, 0x20000001
       sh $t1, 0($t2)
