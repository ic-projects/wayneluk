# exit code: -11
# description: Jumping to non-aligned memory address 0x10000002 should return a Memory Error exception

       .globl entry

entry:
        li $t1, 0x00000008
        sw $t1, 0x10000002($zero)
        li $t0, 0x20000000
        jr $t0
