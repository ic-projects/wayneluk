# exit code: 0
# description: Xoring the same numbers should return 0

        .globl entry

entry:
        li $t1, 0xFFFFFFFF
        li $t2, 0xFFFFFFFF
        xor $v0, $t1, $t2
        jr $zero
