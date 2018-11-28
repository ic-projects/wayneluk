# exit code: -11
# description: Load word right at address 0xFFFFFFC should throw a memory error

        .globl entry

entry:
        li $t1, 0xFFFFFFC
        lwr $t0, 0($t1)
        jr $zero
