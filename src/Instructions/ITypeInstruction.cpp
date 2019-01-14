//
// Created by pranav on 1/13/19.
//

#include <climits>
#include "ITypeInstruction.h"
#include "Instruction.h"
#include "src/CPU.h"

// Decode Immediate Instructions
void CPU::executeIInstruction(uint32_t instruction) {
    switch (OPCODE(instruction)) {
        case ADDI:  return _addi(instruction);
        case ADDIU: return _addiu(instruction);
        case ANDI:  return _andi(instruction);
        case BEQ:   return _beq(instruction);
        case BGTZ:  return _bgtz(instruction);
        case BLEZ:  return _blez(instruction);
        case BNE:   return _bne(instruction);
        case LB:    return _lb(instruction);
        case LBU:   return _lbu(instruction);
        case LH:    return _lh(instruction);
        case LHU:   return _lhu(instruction);
        case LUI:   return _lui(instruction);
        case LW:    return _lw(instruction);
        case LWL:   return _lwl(instruction);
        case LWR:   return _lwr(instruction);
        case ORI:   return _ori(instruction);
        case SB:    return _sb(instruction);
        case SH:    return _sh(instruction);
        case SLTI:  return _slti(instruction);
        case SLTIU: return _sltiu(instruction);
        case SW:    return _sw(instruction);
        case XORI:  return _xori(instruction);
        default:    reportInvalidInstruction(instruction);
    }
}

// ADD Immediate word - Throw arithmetic error if overflow detected
void CPU::_addi(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t imm = IMM(instruction);
    int32_t a = (int32_t)readRegister(regs);
    int32_t b = (int16_t)imm;

    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        std::cerr << "Integer overflow detected (" << a << " + " << b << ")" << std::endl;
        std::exit(ARITHERR);
    }
    writeRegister(regt, a + b);

}

// ADD Immediate Unsigned word - no overflow error thrown
void CPU::_addiu(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm  = IMM(instruction);
    writeRegister(regt, (int32_t)readRegister(regs) + (int32_t)imm);

}


// AND Immediate word
void CPU::_andi(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint16_t imm = IMM(instruction);

    int32_t source = readRegister(regs);
    uint32_t result = source & (uint32_t)imm;
    writeRegister(regt, result);

}

// Branch on Equal -  address is 18 bits (16 bit offset immediate value shift left 2 bits) - PC Reletaive
void CPU::_beq(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);
    if (readRegister(regs) == readRegister(regt)) {
        advanceProgramCounter((imm << 2));
        updatePC = false;
    }
}

// Branch on Greater Than Zero -  address is 18 bits (16 bit offset immediate value shift left 2 bits) - PC Reletaive
void CPU::_bgtz(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm = IMM(instruction);

    if ((int32_t)readRegister(regs) > 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }
}

// Branch on Less Than Zero -  address is 18 bits (16 bit offset immediate value shift left 2 bits) - PC Reletaive
void CPU::_blez(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    int16_t imm =  IMM(instruction);

    if ((int32_t)readRegister(regs) <= 0) {
        advanceProgramCounter((imm << SHIFT2));
        updatePC = false;
    }
}
// Branch on Not Equal -  address is 18 bits (16 bit offset immediate value shift left 2 bits) - PC Reletaive
void CPU::_bne(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    if (readRegister(regs) != readRegister(regt)) {
        int32_t signExtImm = imm << SHIFT2;
        advanceProgramCounter(signExtImm);
        updatePC = false;
    }
}

// Load byte from memory as a signed value - memory address is the value in source register + immediate value
void CPU::_lb(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    int8_t data = memory->readByte(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, (int32_t)data);

}

// Load byte from memory as an usigned value - memory address is the value in source register + immediate value
void CPU::_lbu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    uint32_t data = memory->readByte(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, data);

}

// Load halfword from memory as a signed value - memory address is the value in source register + immediate value
void CPU::_lh(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    int16_t data = memory->readHalfWord(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, (int32_t)data);

}

// Load halfword from memory as an usigned value - memory address is the value in source register + immediate value
void CPU::_lhu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    uint32_t data = memory->readHalfWord(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, data);

}

// Load Immediate constant in Upper half of a word.
void CPU::_lui(uint32_t instruction)
{
    uint32_t regt = REGT(instruction);
    uint16_t imm = IMM(instruction);

    writeRegister(regt, imm << SHIFT16);

}

// Load word from memory as a signed value - memory address is the value in source register + immediate value
void CPU::_lw(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    writeRegister(regt, memory->readWord(readRegister(regs) + imm));

}

// Load word left - Load the most significant part of a word as a signed value from an unalligned memory
void CPU::_lwl(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    uint32_t effAddr = readRegister(regs) + (int32_t) imm;
    uint32_t remainder = effAddr % 4;
    uint32_t mask = ALLBITS >> (8 * (remainder));
    uint32_t resultMask;
    if(remainder == 0){
        resultMask = 0;
    } else {
        resultMask = ALLBITS >> (8 * (4 - remainder));
    }
    // Read word from alligned memory
    uint32_t memData = memory->readWord(effAddr - remainder);
    //Get the most significant part
    uint32_t data = (memData & mask) << ((remainder) * 8);
    uint32_t storedData = readRegister(regt);
    uint32_t newData = (storedData & resultMask) | data;

    writeRegister(regt, newData);

}


// Load Word Right - Load the least significant part of a word as a signed value from an unalligned memory
void CPU::_lwr(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);


    uint32_t effAddr = (int32_t)readRegister(regs) + (int32_t) imm;
    uint32_t remainder = effAddr % 4;
    uint32_t mask = ALLBITS << (8 * (3 - remainder));
    uint32_t resultMask;
    if(remainder == 3){
        resultMask = 0;
    } else {
        resultMask = ALLBITS << (8 * (remainder + 1));
    }
    // Read word from alligned memory
    uint32_t memData = memory->readWord(effAddr - remainder);
    // Get the least significant part
    uint32_t data = (memData & mask) >> ((3- remainder) * 8);
    uint32_t storedData = readRegister(regt);
    uint32_t newData = (storedData & resultMask) | data;

    writeRegister(regt, newData);

}


// logical OR a zero extended Immediate value
void CPU::_ori(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint16_t imm = IMM(instruction);

    int32_t source = readRegister(regs);
    uint32_t result = source | imm;
    writeRegister(regt, result);

}

// Store Byte into memory - address is the value in the source register + the immediate value
void CPU::_sb(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    memory->writeByte(readRegister(regs) + (int32_t)imm, readRegister(regt) & FIRST8);

}

// Store HalfWord into memory - address is the value in the source register + the immediate value
void CPU::_sh(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    memory->writeHalfWord(readRegister(regs) + (int32_t)imm, (readRegister(regt) & FIRST16));

}


// Set on Less Than Immediate - if the value in source is less than the sign extended immediate value return 1 else 0
void CPU::_slti(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regd =  REGT(instruction);
    int16_t imm = IMM(instruction);

    writeRegister(regd, ((int32_t) readRegister(regs) < (int32_t)imm));

}


// Set on Less Than Immediate - if the value in source is less than the unsigned immediate value return 1 else 0
void CPU::_sltiu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regd =  REGT(instruction);
    int16_t imm = IMM(instruction);

    int32_t signExt = imm;
    writeRegister(regd, (uint32_t) (readRegister(regs) < (uint32_t)signExt));

}

// Store Word in memory - address is the value in source register + the immediate value.
void CPU::_sw(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    int16_t imm = IMM(instruction);

    memory->writeWord(readRegister(regs) + (int32_t)imm, readRegister(regt));

}

// XOR Zero Extended Immediate Value
void CPU::_xori(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint16_t imm = IMM(instruction);

    uint32_t zeroExtImm = imm;
    writeRegister(regt, readRegister(regs) ^ zeroExtImm);

}
