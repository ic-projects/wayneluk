//
// Created by jordan on 03/11/18.
//

#include "JumpInstruction.h"

JumpInstruction::JumpInstruction(uint32_t instruction) : Instruction() {
    opcode = instruction >> OPCODE_SHIFT;
    target = instruction & TARGET_MASK;
}

void JumpInstruction::execute(CPU *cpu) {
}
