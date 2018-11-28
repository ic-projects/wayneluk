# exit code: 30
# description: Load a constant into a register
        .globl entry

entry:
        lui $v0, 30
        srl $v0, 16
        jr $zero
