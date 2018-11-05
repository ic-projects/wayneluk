# exit code: -11
# description: Memory access at unreadable address 0x30000004 should cause a Memory Error exception

       .globl entry

entry:
        lw $t1, 0x30000004
