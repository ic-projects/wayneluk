//
// Created by jordan on 03/11/18.
//

#ifndef SIMULATOR_JUMPINSTRUCTION_H
#define SIMULATOR_JUMPINSTRUCTION_H

#include "Instruction.h"

#define TARGET_MASK 0x03E00000

class JumpInstruction : public Instruction {
public:
    explicit JumpInstruction(uint32_t instruction);
    void execute(CPU *cpu) override;
private:
    /*
     * Opcode | Target
     * 31-26  | 25-0
     */
    int8_t opcode;
    int32_t target;
};

#endif //SIMULATOR_JUMPINSTRUCTION_H
