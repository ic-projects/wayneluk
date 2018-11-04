//
// Created by jordan on 03/11/18.
//

#include "RegisterInstruction.h"
#include "JumpInstruction.h"
#include "ImmediateInstruction.h"

Instruction *InstructionDecoder::decodeInstruction(uint32_t instruction) {
    uint8_t opcode = instruction >> OPCODE_SHIFT;
    if (opcode == 0) {
        return new RegisterInstruction(instruction);
    }
    if (opcode == 2 || opcode == 3) {
        return new JumpInstruction(instruction);
    }
    return new ImmediateInstruction(instruction);
}
