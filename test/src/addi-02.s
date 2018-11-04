# exit code: -10
# description: FIXME: Overflow checking of addi instruction

        .globl entry

entry:
        lui $t2, 100
        # doesn't compile
        # addi $t0, $t2, 2147483647
