# exit code: -11
# description: Memory access at unreadable address 0x11000000 should cause a Memory Error exception

       .globl entry

entry:
        lw $t1, 0x11000000
        jr $zero
