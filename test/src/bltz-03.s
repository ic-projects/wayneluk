# exit code: 2
# description: Branch less than with negative offset

        .globl entry

entry:
        addiu $t0, $0, -5
        bltz $t0, jump
        addiu $v0, $0, 1
break:
        jr $zero
jump:
        addiu $v0, $v0, 2
        bltz $t0, break
        addiu $v0, $v0, 1
        jr $zero
