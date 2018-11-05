# exit code: 0
# description: Implementation specific lb IO
      .globl entry
entry:
       li $t1, 5
       sb $t1, 0x30000007($t0)