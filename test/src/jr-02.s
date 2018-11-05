# exit code: -11
# description: Jumping to non-executable memory at address 0x20000000 should return a Memory Error exception

       .globl entry

entry:
        li $t1, 0x00000008
        sw $t1, 0x20000000($zero)
        li $t0, 0x20000000
        jr $t0
