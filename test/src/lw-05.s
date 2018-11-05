# exit code: -11
# description: Unaligned memory access at 0x20000002 should cause a Memory Error exception

       .globl entry

entry:
        lw $t1, 0x20000002
