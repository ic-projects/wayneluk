# exit code: 0
# description: Aligned memory access at 0x20000000 should return 0

       .globl entry

entry:
        lw $v0, 0x20000000
        jr $zero
