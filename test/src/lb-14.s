# exit code: -1
# description: Loading a byte 0x80 should be sign-extended

        .globl entry

entry:
        li $t0, 0x20000000
        li $t1, 0x80
        sb $t1, 3($t0)
        lb $v0, 3($t0)
        sra $v0, $v0, 8
        jr $zero
