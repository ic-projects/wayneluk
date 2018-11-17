# exit code: 2
# description: Branch negative offset

        .globl entry

entry:
        addiu $v0, $0, 0
        beq $0, $0, jump
        addiu $v0, $0, 1
break:
        jr $zero
jump:
        addiu $v0, $v0, 2
        beq $0, $0, break
        addiu $v0, $0, 1
        jr $zero
