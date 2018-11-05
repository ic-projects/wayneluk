# exit code: 0
# description: Add the numbers 25 and 15
       .globl entry
entry:
       addi $t1, $0, 20
       addi $t0, $0, 15
       add $t5, $t0, $t1
