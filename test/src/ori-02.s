# exit code: 13
# description: ORI 5 and 9 should return 13

        .globl entry

entry:
        ori $t0, $0, 5
        ori $v0, $t0, 9
        jr $zero
