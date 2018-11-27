# exit code: -11
# description: Loading word left at address 0x0 should throw a memory error

        .globl entry

entry:
        li $t1, 0x0
        lwl $t0, 0($t1)
        jr $zero
