# exit code: -11
# description: Load word left at address 0xFFFFFFC should throw a memory error

        .globl entry

entry:
        li $t1, 0xFFFFFFC
        lwl $t0, 0($t1)
        jr $zero
