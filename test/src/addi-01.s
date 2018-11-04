# exit code: 10
# description: Test the functionality  of addi instruction

        .globl entry

entry:
        lui $t3, 10
        addi $t1, $t3, -10
