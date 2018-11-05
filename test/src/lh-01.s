# exit code: 0
# description: Implementation specific lh IO
       .globl entry
entry:
        li $t1, 0x30000002
        lh $t0, 0($t1)