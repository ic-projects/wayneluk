# exit code: 0
# description: Add the numbers 5 and 1

       .globl entry
entry:
       lui $t0, 5
       lui $t1, 1
       add $t0, $t0, $t1
