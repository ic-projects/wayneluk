# exit code: 16777215
# description: OR 0xFFFFFF and 0 return 0xFFFFFF

        .globl entry

entry:
        li $t1, 0xFFFFFF
        li $t2, 0
        or $v0, $t1, $t2
        jr $zero
