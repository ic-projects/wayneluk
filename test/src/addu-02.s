# exit code: 4294967279
# description: Adding two large numbers should overflow without causing an exception

        .globl entry

entry:
        li $t0, 0xFFFFFFFF
        li $t1, 0xFFFFFFF0
        addu $v0, $t0, $t1
        jr $zero
