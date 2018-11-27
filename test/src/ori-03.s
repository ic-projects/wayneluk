# exit code: 4275878553
# description: ORI 0xFEDCBA98 and 0xF should return 0xFEDCBA99

        .globl entry

entry:
        li $t0, 0xFEDCBA98
        ori $v0, $t0, 0x9
        jr $zero
