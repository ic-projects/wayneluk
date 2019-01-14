//
// Created by jordan on 04/11/18.
//

#include <climits>
#include <cstdint>
#include "src/CPU.h"
#include "Instruction.h"
#include "src/CPU.h"

// Find the correct type of instruction
void CPU::executeInstruction(uint32_t instruction) {
    switch (OPCODE(instruction)) {
        case R:
            return executeRInstruction(instruction);
        case 2:
        case 3:
            return executeJInstruction(instruction);
        case B_OTHER:
            return executeBOtherInstruction(instruction);
        default:
            return executeIInstruction(instruction);
    }
}

// Execute Branch Instructions
void CPU::executeBOtherInstruction(uint32_t instruction) {
    switch (REGT(instruction)) {
        case BGEZ:      return _bgez(instruction);
        case BGEZAL:    return _bgezal(instruction);
        case BLTZ:      return _bltz(instruction);
        case BLTZAL:    return _bltzal(instruction);
        default:        reportInvalidInstruction(instruction);
    }
}

// Throw error if instruction is not implemented
void CPU::reportInvalidInstruction(uint32_t instruction) {
    std::cerr << "Attempted to execute invalid instruction (opcode: 0x" << std::hex << OPCODE(instruction) << ")"
              << std::endl;
    std::exit(-12);
}

// Branch on greater than or equal to zero
void CPU::_bgez(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm = IMM(instruction);

    if ((int32_t)readRegister(regs) >= 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }

}

// Branch on greater than or equal to 0 and link - add the return address to GRP 31
void CPU::_bgezal(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm = IMM(instruction);

    writeRegister(31, getProgramCounter() + 8);
    if((int32_t)readRegister(regs) >= 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }
}

// Branch on Less Than Zero
void CPU::_bltz(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm = IMM(instruction);

    if ((int32_t)readRegister(regs) < 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }
}

// Branch on Less Than or Equal to Zero and Link - add the return address to GRP 31
void CPU::_bltzal(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm = IMM(instruction);

    writeRegister(31, getProgramCounter() + 8);
    if((int32_t)readRegister(regs) < 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }
}

