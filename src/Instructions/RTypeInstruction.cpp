//
// Created by pranav on 1/13/19.
//

#include <climits>
#include "RTypeInstruction.h"
#include "src/Instructions/Instruction.h"
#include "src/CPU.h"


void CPU::executeRInstruction(uint32_t instruction) {
    switch (FNCODE(instruction)) {
        case ADD:   return _add(instruction);
        case ADDU:  return _addu(instruction);
        case AND:   return _and(instruction);
        case DIV:   return _div(instruction);
        case DIVU:  return _divu(instruction);
        case JALR:  return _jalr(instruction);
        case JR:    return _jr(instruction);
        case MFHI:  return _mfhi(instruction);
        case MFLO:  return _mflo(instruction);
        case MTHI:  return _mthi(instruction);
        case MTLO:  return _mtlo(instruction);
        case MULT:  return _mult(instruction);
        case MULTU: return _multu(instruction);
        case OR:    return _or(instruction);
        case SLL:   return _sll(instruction);
        case SLLV:  return _sllv(instruction);
        case SLT:   return _slt(instruction);
        case SLTU:  return _sltu(instruction);
        case SRA:   return _sra(instruction);
        case SRAV:  return _srav(instruction);
        case SRL:   return _srl(instruction);
        case SRLV:  return _srlv(instruction);
        case SUB:   return _sub(instruction);
        case SUBU:  return _subu(instruction);
        case XOR:   return _xor(instruction);
        default:    reportInvalidInstruction(instruction);
    }
}

// ADD two signed values together - throw an Arithmetic Error if overflow detected
void CPU::_add(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);
    int32_t a = readRegister(regs);
    int32_t b = readRegister(regt);

    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        std::cerr << "Integer overflow detected (" << a << " + " << b << ")" << std::endl;
        std::exit(ARITHERR);
    }
    writeRegister(regd, a + b);
}

// ADD Unsigned values together - no Error thrown.
void CPU::_addu(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regst = REGT(instruction);
    uint32_t regsd = REGD(instruction);
    writeRegister(regsd, (int32_t)readRegister(regs) + (int32_t)readRegister(regst));
}

// AND two values together
void CPU::_and(uint32_t instruction) {
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, readRegister(regs) & readRegister(regt));
}

// DIVIDE and MODULO the signed source by the signed divider and store them in the LO and HIGH registers respectively.
// If divider is 0 then return -  No Error Thrown.
void CPU::_div(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);

    int32_t divider = readRegister(regt);
    if (divider == 0) {
        return;
    }
    writeLORegister((int32_t) readRegister(regs) / divider);
    writeHIRegister((int32_t) readRegister(regs) % divider);
}

// DIVIDE and MODULO the source by the divider and store them in the LO and HIGH registers respectively.
// If divider is 0 then return -  No Error Thrown.
void CPU::_divu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);

    uint32_t divider = readRegister(regt);
    if (divider == 0) {
        return;
    }
    writeLORegister(readRegister(regs) / divider);
    writeHIRegister(readRegister(regs) % divider);
}
// Jump And Link Register
void CPU::_jalr(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, getProgramCounter() + 8);
    setProgramCounter(readRegister(regs));
    updatePC = false;
}

//Jump Register
void CPU::_jr(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    setProgramCounter(readRegister(regs));
    updatePC = false;
}

// Move the Value in the HIGH register to a GPR
void CPU::_mfhi(uint32_t instruction)
{
    uint32_t regd = REGD(instruction);
    writeRegister(regd, readHIRegister());

}

// Move the Value in the LO register to a GPR
void CPU::_mflo(uint32_t instruction)
{
    uint32_t regd = REGD(instruction);
    writeRegister(regd, readLORegister());
}

// Move the Value from the source register to the HIGH register
void CPU::_mthi(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    writeHIRegister(readRegister(regs));
}

// Move the Value from the source register to the LO register
void CPU::_mtlo(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    writeLORegister(readRegister(regs));
}

// MUltiply two signed values together and save the top 32 bit word in the HIGH register and
// the bottom 32 bit word to the LO register
void CPU::_mult(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);

    int64_t sourceReg = (int32_t) readRegister(regs);
    int64_t otherSourceReg = (int32_t) readRegister(regt);
    int64_t result = (sourceReg * otherSourceReg);
    writeHIRegister((result & HIGHMASK) >> SHIFT32);
    writeLORegister((result & LOMASK));
}

// MUltiply two unsigned values together and save the top 32 bit word in the HIGH register and
// the bottom 32 bit word to the LO register
void CPU::_multu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);

    uint64_t result = (uint64_t)readRegister(regs) * (uint64_t)readRegister(regt);
    writeHIRegister((result & HIGHMASK) >> SHIFT32);
    writeLORegister((result & LOMASK));
}

// OR two values together
void CPU::_or(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, readRegister(regs) | readRegister(regt));
}

// Shift Left by shift amount
void CPU::_sll(uint32_t instruction)
{
    uint32_t regs = REGT(instruction);
    uint32_t regd = REGD(instruction);
    uint32_t shiftAmt = SHIFTAMT(instruction);

    writeRegister(regd, (readRegister(regs)) << shiftAmt);
}

// Shift Left by the bottom 5 bits (max shift is 31) of the source register
void CPU::_sllv(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, (readRegister(regt)) << (readRegister(regs) & FIVEBITS));
}

// Set if Less Than -  signed source is less than signed otherSource then return 1 else return 0
void CPU::_slt(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, ((int32_t) readRegister(regs) < (int32_t) readRegister(regt)));
}

//  Set if Less Than -  Unsigned source is less than signed otherSource then return 1 else return 0
void CPU::_sltu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, (uint32_t) (readRegister(regs) < readRegister(regt)));
}

// Shift Right by shift amount a signed value
void CPU::_sra(uint32_t instruction)
{
    uint32_t regs = REGT(instruction);
    uint32_t regd = REGD(instruction);
    uint32_t shiftAmt = SHIFTAMT(instruction);

    writeRegister(regd, ((int32_t) readRegister(regs)) >> shiftAmt);
}

// Shift Right by the bottom 5 bits of the source register
void CPU::_srav(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, ((int32_t) readRegister(regt)) >> (readRegister(regs) & FIVEBITS));
}

// Shift Right by shift amount an unsigned value
void CPU::_srl(uint32_t instruction)
{
    uint32_t regs = REGT(instruction);
    uint32_t regd = REGD(instruction);
    uint32_t shiftAmt = SHIFTAMT(instruction);
    writeRegister(regd, readRegister(regs) >> shiftAmt);
}

// Shift Right by the bottom 5 bits of the source register a signed value
void CPU::_srlv(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, readRegister(regt) >> (readRegister(regs) & FIVEBITS));
}

// Subtract two signed values. Throw Arithmetic Error if overflow detected.
void CPU::_sub(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    int32_t sourceRegister = readRegister(regs);
    int32_t otherSourceRegister = readRegister(regt);
    int32_t result = sourceRegister - otherSourceRegister;

    if (((sourceRegister < 0 ) && (otherSourceRegister > 0) && (result >= 0)) ||
        ((sourceRegister > 0) && (otherSourceRegister < 0) && (result <= 0))) {
        std::cerr << "Integer overflow detected (" << sourceRegister << " - " << otherSourceRegister << ")" << std::endl;
        exit(ARITHERR);
    }
    writeRegister(regd, result);
}

// Subtract two unsigned values. Throw Arithmetic Error if overflow detected.
void CPU::_subu(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, (int32_t)readRegister(regs) - (int32_t)readRegister(regt));
}

// XOR two values together
void CPU::_xor(uint32_t instruction)
{
    uint32_t regs = REGS(instruction);
    uint32_t regt = REGT(instruction);
    uint32_t regd = REGD(instruction);

    writeRegister(regd, readRegister(regs) ^ readRegister(regt));
}


