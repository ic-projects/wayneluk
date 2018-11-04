//
// Created by jordan on 03/11/18.
//

#include "ImmediateInstruction.h"

ImmediateInstruction::ImmediateInstruction(uint32_t instruction) : Instruction() {
    opcode = instruction >> OPCODE_SHIFT;
    register1 = (instruction & REGISTER1_MASK) >> REGISTER1_SHIFT;
    register2 = (instruction & REGISTER2_MASK) >> REGISTER2_SHIFT;
    immediate = instruction & IMMEDIATE_MASK;
}

void ImmediateInstruction::execute(CPU *cpu) {
}
