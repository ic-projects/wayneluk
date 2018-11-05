# exit code: 0
# description: addu 50 + 50 = 100

        .globl entry

entry:
        addiu $t0, $0, 50
        addu $t1, $t0, $t0
