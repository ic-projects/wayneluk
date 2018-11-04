//
// Created by jordan on 03/11/18.
//

#include "RegisterInstruction.h"

RegisterInstruction::RegisterInstruction(uint32_t instruction) : Instruction() {
    opcode = instruction >> OPCODE_SHIFT;
    register1 = (instruction & REGISTER1_MASK) >> REGISTER1_SHIFT;
    register2 = (instruction & REGISTER2_MASK) >> REGISTER2_SHIFT;
    registerDest = (instruction & REGISTERDEST_MASK) >> REGISTERDEST_SHIFT;
    shiftAmount = (instruction & SHIFTAMOUNT_MASK) >> SHIFTAMOUNT_SHIFT;
    functionCode = instruction & FUNCTIONCODE_MASK;
}

void RegisterInstruction::execute(CPU *cpu) {
}
