# exit code: 0
# description: Implementation specific lb IO
       .globl entry
entry:
        li $t1, 0x30000003
        lb $t0, 0($t1)
