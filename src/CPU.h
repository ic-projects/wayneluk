//
// Created by jordan on 03/11/18.
//
#include <iostream>
#include <cstdint>

#ifndef SIMULATOR_CPU_H
#define SIMULATOR_CPU_H

#include "src/Memory.h"

class CPU {
public:
    // Constructor
    CPU(Memory *memory);
    // Simulate
    void simulate();
    // Registers
    uint32_t readRegister(uint32_t reg);
    void writeRegister(uint32_t reg, uint32_t val);
private:
    // Registers
    uint32_t programCounter = ADDR_INSTR;
    uint32_t registerFile[32] = {0};
    // Memory
    Memory *memory;
    // Instructions
    void executeInstruction(uint32_t instruction);
    void executeRInstruction(uint32_t instruction);
    void executeBranchInstruction(uint32_t instruction);
    void reportInvalidInstruction(uint32_t instruction);
    void addi(uint32_t regs, uint32_t regt, uint32_t imm);
    void lui(uint32_t regt, uint32_t imm);
    void sb(uint32_t regs, uint32_t regt, uint32_t imm);
    void sw(uint32_t regs, uint32_t regt, uint32_t imm);
};

#endif //SIMULATOR_CPU_H
