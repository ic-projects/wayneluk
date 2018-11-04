//
// Created by jordan on 03/11/18.
//

#ifndef SIMULATOR_INSTRUCTION_H
#define SIMULATOR_INSTRUCTION_H

#define OPCODE_SHIFT 26

#include "src/CPU/CPU.h"

class Instruction {
public:
    virtual void execute(CPU *cpu) = 0;
};

class InstructionDecoder {
public:
    static Instruction *decodeInstruction(uint32_t instruction);
};

#endif //SIMULATOR_INSTRUCTION_H
