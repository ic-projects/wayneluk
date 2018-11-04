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
    void setProgramCounter(uint32_t address);
    uint32_t getProgramCounter();
    uint32_t readHIRegister();
    void writeHIRegister(uint32_t val);
    uint32_t readLORegister();
    void writeLORegister(uint32_t val);
private:
    // Registers
    uint32_t programCounter = ADDR_INSTR;
    uint32_t registerFile[32] = {0};
    uint32_t HI = {0};
    uint32_t LO = {0};
    // Memory
    Memory *memory;
    // Instructions
    void executeInstruction(uint32_t instruction);
    void executeRInstruction(uint32_t instruction);
    void executeBranchInstruction(uint32_t instruction);
    void reportInvalidInstruction(uint32_t instruction);
    void add(uint32_t regs, uint32_t regt, uint32_t regd);
    void addi(uint32_t regs, uint32_t regt, uint32_t imm);
    void addiu(uint32_t regs, uint32_t regt, int32_t signExtImm);
    void addu(uint32_t regs, uint32_t regt, uint32_t regd);
    void logicalAnd(uint32_t regs, uint32_t regt, uint32_t regd);
    void logicalAndI(uint32_t regs, uint32_t regt, int32_t zeroExtImm);
    void beq(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bgez(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bgezal(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bgtz(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void blez(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bltz(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bltzal(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void bne(uint32_t regs, uint32_t regt, int32_t branchAddr);
    void div(uint32_t regs, uint32_t regt);
    void divu(uint32_t regs, uint32_t regt);
    void j(int32_t addr);
    void jalr(int32_t addr);
    void jal(int32_t addr);
    void jr(uint32_t regs);
    void lb(uint32_t regs, uint32_t regt, int32_t imm);
    void lbu(uint32_t regs, uint32_t regt, int32_t imm);
    void lh(uint32_t regs, uint32_t regt, int32_t imm);
    void lhu(uint32_t regs, uint32_t regt, int32_t imm);
    void lui(uint32_t regt, uint32_t imm);
    void lw(uint32_t regs, uint32_t regt, int32_t signExtImm);
    void lwl(uint32_t regs, uint32_t regt, int32_t imm);
    void lwr(uint32_t regs, uint32_t regt, int32_t imm);
    void mfhi(uint32_t regd);
    void mflo(uint32_t regd);
    void mthi(uint32_t regd);
    void mtlo(uint32_t regd);
    void mult(uint32_t regs, uint32_t regt);
    void multu(uint32_t regs, uint32_t regt);
    void logicalOr(uint32_t regs, uint32_t regt, uint32_t regd);
    void logicalOrI(uint32_t regs, uint32_t regt, int32_t signExtImm);
    void sb(uint32_t regs, uint32_t regt, uint32_t imm);
    void sh(uint32_t regs, uint32_t regt, int32_t signExtImm);

    void sll(uint32_t regs, uint32_t regd, uint32_t shift);
    void sllv(uint32_t regs, uint32_t regt, uint32_t regd);
    void slt(uint32_t regs, uint32_t regt, uint32_t regd);
    void slti(uint32_t regs, uint32_t regd, int32_t constant);
    void sltiu(uint32_t regs, uint32_t regd, uint32_t constant);
    void sltu(uint32_t regs, uint32_t regt, uint32_t regd);
    void sra(uint32_t regs, uint32_t regd, uint32_t shift);
    void srav(uint32_t regs, uint32_t regt, uint32_t regd);
    void srl(uint32_t regs, uint32_t regd, uint32_t shift);
    void srlv(uint32_t regs, uint32_t regt, uint32_t regd);
    void sub(uint32_t regs, uint32_t regt, uint32_t regd);
    void subu(uint32_t regs, uint32_t regt, uint32_t regd);
    void sw(uint32_t regs, uint32_t regt, uint32_t imm);
    void logicalXor(uint32_t regs, uint32_t regt, uint32_t regd);
    void logicalXorI(uint32_t regs, uint32_t regt, uint32_t imm);
};

#endif //SIMULATOR_CPU_H
