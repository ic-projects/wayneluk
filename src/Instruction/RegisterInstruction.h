//
// Created by jordan on 03/11/18.
//

#ifndef SIMULATOR_REGISTERINSTRUCTION_H
#define SIMULATOR_REGISTERINSTRUCTION_H

#include "Instruction.h"

#define REGISTER1_MASK 0x03E00000
#define REGISTER1_SHIFT 21
#define REGISTER2_MASK 0x001F0000
#define REGISTER2_SHIFT 16
#define REGISTERDEST_MASK 0x0000F800
#define REGISTERDEST_SHIFT 11
#define SHIFTAMOUNT_MASK 0x000007C0
#define SHIFTAMOUNT_SHIFT 6
#define FUNCTIONCODE_MASK 0x0000003F

class RegisterInstruction : public Instruction {
public:
    explicit RegisterInstruction(uint32_t instruction);
    void execute(CPU *cpu) override;
private:
    /*
     * Opcode | Register 1 | Register 2 | Register Dest | Shift Amount | Function Code
     * 31-26  | 25-21      | 20-16      | 15-11         | 10-6         | 5-0
     */
    int8_t opcode;
    int8_t register1;
    int8_t register2;
    int8_t registerDest;
    int8_t shiftAmount;
    int8_t functionCode;
};

#endif //SIMULATOR_REGISTERINSTRUCTION_H
