# exit code: 35
# description: Add the numbers 20 and 15 should return 35
       .globl entry
entry:
       addi $t1, $0, 20
       addi $t0, $0, 15
       add $v0, $t0, $t1
       jr $zero
