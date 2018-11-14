# exit code: 50
# description: ORI 0 and 50 return 50

        .globl entry

entry:
        ori $v0, $0, 50
        jr $zero
