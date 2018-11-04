# exit code: -10
# description: FIXME: Overflow error test on the add function
        .globl entry

entry:
        lui $t0, 6
        # does not compile
        #lui $t1, 4294967295
        add $t0, $t1, $t0
