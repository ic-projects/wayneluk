# exit code: -11
# description: Loading halfword at address 0xFFFFFFC should throw a memory error

        .globl entry

entry:
        li $t1, 0xFFFFFFC
        lhu $t0, 0($t1)
        jr $zero
