//
// Created by jordan on 03/11/18.
//
#include <iostream>
#include <cstdint>

#ifndef SIMULATOR_CPU_H
#define SIMULATOR_CPU_H
#define PC_INC 4
#define CPUERR -11


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
    void advanceProgramCounter(int32_t offset);
    void setProgramCounter(uint32_t address);
    uint32_t getProgramCounter();
    uint32_t readHIRegister();
    void writeHIRegister(uint32_t val);
    uint32_t readLORegister();
    void writeLORegister(uint32_t val);
private:
    // Registers
    bool updatePC = true;
    uint32_t programCounter = ADDR_INSTR;
    uint32_t nextProgramCounter = ADDR_INSTR + sizeof(int32_t);
    uint32_t registerFile[32] = {0};
    uint32_t HI = 0;
    uint32_t LO = 0;
    // Memory
    Memory *memory;
    // Instruction helpers (defined in Instruction.cpp)
    void executeInstruction(uint32_t instruction);
    void executeRInstruction(uint32_t instruction);
    void executeIInstruction(uint32_t instruction);
    void executeJInstruction(uint32_t instruction);
    void executeBOtherInstruction(uint32_t instruction);
    void reportInvalidInstruction(uint32_t instruction);

    // Instructions (defined in Instruction.cpp)
    void _add(uint32_t instruction);
    void _addi(uint32_t instruction);
    void _addiu(uint32_t instruction);
    void _addu(uint32_t instruction);
    void _and(uint32_t instruction);
    void _andi(uint32_t instruction);
    void _beq(uint32_t instruction);
    void _bgez(uint32_t instruction);
    void _bgezal(uint32_t instruction);
    void _bgtz(uint32_t instruction);
    void _blez(uint32_t instruction);
    void _bltz(uint32_t instruction);
    void _bltzal(uint32_t instruction);
    void _bne(uint32_t instruction);
    void _div(uint32_t instruction);
    void _divu(uint32_t instruction);
    void _j(uint32_t instruction);
    void _jal(uint32_t instruction);
    void _jalr(uint32_t instruction);
    void _jr(uint32_t instruction);
    void _lb(uint32_t instruction);
    void _lbu(uint32_t instruction);
    void _lh(uint32_t instruction);
    void _lhu(uint32_t instruction);
    void _lui(uint32_t instruction);
    void _lw(uint32_t instruction);
    void _lwl(uint32_t instruction);
    void _lwr(uint32_t instruction);
    void _mfhi(uint32_t instruction);
    void _mflo(uint32_t instruction);
    void _mthi(uint32_t instruction);
    void _mtlo(uint32_t instruction);
    void _mult(uint32_t instruction);
    void _multu(uint32_t instruction);
    void _or(uint32_t instruction);
    void _ori(uint32_t instruction);
    void _sb(uint32_t instruction);
    void _sh(uint32_t instruction);
    void _sll(uint32_t instruction);
    void _sllv(uint32_t instruction);
    void _slt(uint32_t instruction);
    void _slti(uint32_t instruction);
    void _sltiu(uint32_t instruction);
    void _sltu(uint32_t instruction);
    void _sra(uint32_t instruction);
    void _srav(uint32_t instruction);
    void _srl(uint32_t instruction);
    void _srlv(uint32_t instruction);
    void _sub(uint32_t instruction);
    void _subu(uint32_t instruction);
    void _sw(uint32_t instruction);
    void _xor(uint32_t instruction);
    void _xori(uint32_t instruction);
};

#endif //SIMULATOR_CPU_H
