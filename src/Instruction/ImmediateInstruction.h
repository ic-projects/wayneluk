//
// Created by jordan on 03/11/18.
//

//#ifndef SIMULATOR_IMMEDIATEINSTRUCTION_H
//#define SIMULATOR_IMMEDIATEINSTRUCTION_H

#include "Instruction.h"

#define REGISTER1_MASK 0x03E00000
#define REGISTER1_SHIFT 21
#define REGISTER2_MASK 0x001F0000
#define REGISTER2_SHIFT 16
#define IMMEDIATE_MASK 0x0000FFFF

class ImmediateInstruction : public Instruction {
public:
    explicit ImmediateInstruction(uint32_t instruction);
    void execute(CPU *cpu) override;
private:
    /*
     * Opcode | Register 1 | Register 2 | Immediate
     * 31-26  | 25-21      | 20-16      | 15-0
     */
    int8_t opcode;
    int8_t register1;
    int8_t register2;
    int32_t immediate;
};

//#endif //SIMULATOR_IMMEDIATEINSTRUCTION_H
