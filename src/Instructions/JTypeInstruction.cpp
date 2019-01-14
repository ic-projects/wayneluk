//
// Created by pranav on 1/13/19.
//

#include "JTypeInstruction.h"
#include "Instruction.h"
#include "src/CPU.h"

// Decode Jum Instructions
void CPU::executeJInstruction(uint32_t instruction) {
    switch (OPCODE(instruction)) {
        case J:     return _j(instruction);
        case JAL:   return _jal(instruction);
        default:    reportInvalidInstruction(instruction);
    }
}

// Jump to effective address - PC REGION Branch
void CPU::_j(uint32_t instruction) {
    uint32_t target = TARGET(instruction);

    uint32_t address = (getProgramCounter() & LAST4) | (target << SHIFT2);
    setProgramCounter(address);
    updatePC = false;
}

// Jump and Link - put the return address in GPR 31 and jump to effective address
void CPU::_jal(uint32_t instruction) {
    uint32_t target = TARGET(instruction);

    writeRegister(31, getProgramCounter() + 8);
    uint32_t address = (getProgramCounter() & LAST4) | (target << SHIFT2);
    setProgramCounter(address);
    updatePC = false;
}

