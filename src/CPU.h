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
    void setProgramCounter(uint32_t address);
    uint32_t getProgramCounter();
    uint32_t readRegister(uint32_t reg);
    void writeRegister(uint32_t reg, uint32_t val);
    uint32_t readHIRegister();
    void writeHIRegister(uint32_t val);
    uint32_t readLORegister();
    void writeLORegister(uint32_t val);
private:
    // Registers
    uint32_t programCounter = ADDR_INSTR;
    uint32_t registerFile[32] = {0};
    uint32_t HI = 0;
    uint32_t LO = 0;
    // Memory
    Memory *memory;
    // Instruction helpers (defined in Instruction.cpp)
    void executeInstruction(uint32_t instruction);
    void executeRInstruction(uint32_t instruction);
    void executeBOtherInstruction(uint32_t instruction);
    void reportInvalidInstruction(uint32_t instruction);
    // Instructions (defined in Instruction.cpp)
    void _add(uint32_t regs, uint32_t regt, uint32_t regd);
    void _addi(uint32_t regs, uint32_t regt, uint32_t imm);
    void _addiu(uint32_t regs, uint32_t regt, int32_t imm);
    void _addu(uint32_t regs, uint32_t regt, uint32_t regd);
    void _and(uint32_t regs, uint32_t regt, uint32_t regd);
    void _andi(uint32_t regs, uint32_t regt, int32_t imm);
    void _beq(uint32_t regs, uint32_t regt, int32_t imm);
    void _bgez(uint32_t regs, uint32_t regt, int32_t imm);
    void _bgezal(uint32_t regs, uint32_t regt, int32_t imm);
    void _bgtz(uint32_t regs, uint32_t regt, int32_t imm);
    void _blez(uint32_t regs, uint32_t regt, int32_t imm);
    void _bltz(uint32_t regs, uint32_t regt, int32_t imm);
    void _bltzal(uint32_t regs, uint32_t regt, int32_t imm);
    void _bne(uint32_t regs, uint32_t regt, int32_t imm);
    void _div(uint32_t regs, uint32_t regt);
    void _divu(uint32_t regs, uint32_t regt);
    void _j(int32_t target);
    void _jal(int32_t target);
    void _jalr(uint32_t regs, uint32_t regd);
    void _jr(uint32_t regs);
    void _lb(uint32_t regs, uint32_t regt, int32_t imm);
    void _lbu(uint32_t regs, uint32_t regt, int32_t imm);
    void _lh(uint32_t regs, uint32_t regt, int32_t imm);
    void _lhu(uint32_t regs, uint32_t regt, int32_t imm);
    void _lui(uint32_t regt, uint32_t imm);
    void _lw(uint32_t regs, uint32_t regt, int32_t imm);
    void _lwl(uint32_t regs, uint32_t regt, int32_t imm);
    void _lwr(uint32_t regs, uint32_t regt, int32_t imm);
    void _mfhi(uint32_t regd);
    void _mflo(uint32_t regd);
    void _mthi(uint32_t regd);
    void _mtlo(uint32_t regd);
    void _mult(uint32_t regs, uint32_t regt);
    void _multu(uint32_t regs, uint32_t regt);
    void _or(uint32_t regs, uint32_t regt, uint32_t regd);
    void _ori(uint32_t regs, uint32_t regt, int32_t imm);
    void _sb(uint32_t regs, uint32_t regt, uint32_t imm);
    void _sh(uint32_t regs, uint32_t regt, int32_t imm);
    void _sll(uint32_t regs, uint32_t regd, uint32_t shiftAmt);
    void _sllv(uint32_t regs, uint32_t regt, uint32_t regd);
    void _slt(uint32_t regs, uint32_t regt, uint32_t regd);
    void _slti(uint32_t regs, uint32_t regd, int32_t imm);
    void _sltiu(uint32_t regs, uint32_t regd, uint32_t imm);
    void _sltu(uint32_t regs, uint32_t regt, uint32_t regd);
    void _sra(uint32_t regs, uint32_t regd, uint32_t shiftAmt);
    void _srav(uint32_t regs, uint32_t regt, uint32_t regd);
    void _srl(uint32_t regs, uint32_t regd, uint32_t shiftAmt);
    void _srlv(uint32_t regs, uint32_t regt, uint32_t regd);
    void _sub(uint32_t regs, uint32_t regt, uint32_t regd);
    void _subu(uint32_t regs, uint32_t regt, uint32_t regd);
    void _sw(uint32_t regs, uint32_t regt, uint32_t imm);
    void _xor(uint32_t regs, uint32_t regt, uint32_t regd);
    void _xori(uint32_t regs, uint32_t regt, uint32_t imm);
};

#endif //SIMULATOR_CPU_H
