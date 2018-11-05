# exit code: -11
# description: Unaligned memory access should cause a Memory Error exception

       .globl entry

entry:
        li $t1, 0x30000001
