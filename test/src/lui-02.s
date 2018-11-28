# exit code: 205
# description: Load a constant into a register
        .globl entry

entry:
        lui $v0, 0xABCD
        srl $v0, 16
        jr $zero
