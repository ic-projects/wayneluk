//
// Created by jordan on 04/11/18.
//

#include <climits>
#include <cstdint>
#include "CPU.h"
#include "Instruction.h"

void CPU::executeInstruction(uint32_t instruction) {
    switch (OPCODE(instruction)) {
        case R:
            return executeRInstruction(instruction);
        case ADDI:
            return _addi(REGS(instruction), REGT(instruction), IMM(instruction));
        case ADDIU:
            return _addiu(REGS(instruction), REGT(instruction), IMM(instruction));
        case ANDI:
            return _andi(REGS(instruction), REGT(instruction), IMM(instruction));
        case BEQ:
            return _beq(REGS(instruction), REGT(instruction), IMM(instruction));
        case B_OTHER:
            return executeBOtherInstruction(instruction);
        case BGTZ:
            return _bgtz(REGS(instruction), IMM(instruction));
        case BLEZ:
            return _blez(REGS(instruction), IMM(instruction));
        case BNE:
            return _bne(REGS(instruction), REGT(instruction), IMM(instruction));
        case J:
            return _j(TARGET(instruction));
        case JAL:
            return _jal(TARGET(instruction));
        case LB:
            return _lb(REGS(instruction), REGT(instruction), IMM(instruction));
        case LBU:
            return _lbu(REGS(instruction), REGT(instruction), IMM(instruction));
        case LH:
            return _lh(REGS(instruction), REGT(instruction), IMM(instruction));
        case LHU:
            return _lhu(REGS(instruction), REGT(instruction), IMM(instruction));
        case LUI:
            return _lui(REGT(instruction), IMM(instruction));
        case LW:
            return _lw(REGS(instruction), REGT(instruction), IMM(instruction));
        case LWL:
            return _lwl(REGS(instruction), REGT(instruction), IMM(instruction));
        case LWR:
            return _lwr(REGS(instruction), REGT(instruction), IMM(instruction));
        case ORI:
            return _ori(REGS(instruction), REGT(instruction), IMM(instruction));
        case SB:
            return _sb(REGS(instruction), REGT(instruction), IMM(instruction));
        case SH:
            return _sh(REGS(instruction), REGT(instruction), IMM(instruction));
        case SLTI:
            return _slti(REGS(instruction), REGT(instruction), IMM(instruction));
        case SLTIU:
            return _sltiu(REGS(instruction), REGT(instruction), IMM(instruction));
        case SW:
            return _sw(REGS(instruction), REGT(instruction), IMM(instruction));
        case XORI:
            return _xori(REGS(instruction), REGT(instruction), IMM(instruction));
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::executeRInstruction(uint32_t instruction) {
    switch (FNCODE(instruction)) {
        case ADD:
            return _add(REGS(instruction), REGT(instruction), REGD(instruction));
        case ADDU:
            return _addu(REGS(instruction), REGT(instruction), REGD(instruction));
        case AND:
            return _and(REGS(instruction), REGT(instruction), REGD(instruction));
        case DIV:
            return _div(REGS(instruction), REGT(instruction));
        case DIVU:
            return _divu(REGS(instruction), REGT(instruction));
        case JALR:
            return _jalr(REGS(instruction), REGD(instruction));
        case JR:
            return _jr(REGS(instruction));
        case MFHI:
            return _mfhi(REGD(instruction));
        case MFLO:
            return _mflo(REGD(instruction));
        case MTHI:
            return _mthi(REGS(instruction));
        case MTLO:
            return _mtlo(REGS(instruction));
        case MULT:
            return _mult(REGS(instruction), REGT(instruction));
        case MULTU:
            return _multu(REGS(instruction), REGT(instruction));
        case OR:
            return _or(REGS(instruction), REGT(instruction), REGD(instruction));
        case SLL:
            return _sll(REGT(instruction), REGD(instruction), SHIFTAMT(instruction));
        case SLLV:
            return _sllv(REGS(instruction), REGT(instruction), REGD(instruction));
        case SLT:
            return _slt(REGS(instruction), REGT(instruction), REGD(instruction));
        case SLTU:
            return _sltu(REGS(instruction), REGT(instruction), REGD(instruction));
        case SRA:
            return _sra(REGT(instruction), REGD(instruction), SHIFTAMT(instruction));
        case SRAV:
            return _srav(REGS(instruction), REGT(instruction), REGD(instruction));
        case SRL:
            return _srl(REGT(instruction), REGD(instruction), SHIFTAMT(instruction));
        case SRLV:
            return _srlv(REGS(instruction), REGT(instruction), REGD(instruction));
        case SUB:
            return _sub(REGS(instruction), REGT(instruction), REGD(instruction));
        case SUBU:
            return _subu(REGS(instruction), REGT(instruction), REGD(instruction));
        case XOR:
            return _xor(REGS(instruction), REGT(instruction), REGD(instruction));
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::executeBOtherInstruction(uint32_t instruction) {
    switch (REGT(instruction)) {
        case BGEZ:
            return _bgez(REGS(instruction), IMM(instruction));
        case BGEZAL:
            return _bgezal(REGS(instruction), IMM(instruction));
        case BLTZ:
            return _bltz(REGS(instruction), IMM(instruction));
        case BLTZAL:
            return _bltzal(REGS(instruction), IMM(instruction));
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::reportInvalidInstruction(uint32_t instruction) {
    std::cerr << "Attempted to execute invalid instruction (opcode: 0x" << std::hex << OPCODE(instruction) << ")"
              << std::endl;
    std::exit(-12);
}


void CPU::_add(uint32_t regs, uint32_t regt, uint32_t regd) {
    int32_t a = readRegister(regs);
    int32_t b = readRegister(regt);

    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        std::cerr << "Integer overflow detected (" << a << " + " << b << ")" << std::endl;
        std::exit(-10);
    }
    writeRegister(regd, a + b);
    advanceProgramCounter(4);
}

void CPU::_addi(uint32_t regs, uint32_t regt, uint32_t imm) {
    int32_t a = (int32_t)readRegister(regs);
    int32_t b = (int16_t)imm;

    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        std::cerr << "Integer overflow detected (" << a << " + " << b << ")" << std::endl;
        std::exit(-10);
    }
    writeRegister(regt, a + b);
    advanceProgramCounter(4);
}

void CPU::_addiu(uint32_t regs, uint32_t regt, int16_t imm) {
    writeRegister(regt, (int32_t)readRegister(regs) + (int32_t)imm);
    advanceProgramCounter(4);
}

void CPU::_addu(uint32_t regs, uint32_t regst, uint32_t regsd) {
    writeRegister(regsd, (int32_t)readRegister(regs) + (int32_t)readRegister(regst));
    advanceProgramCounter(4);
}

void CPU::_and(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) & readRegister(regt));
    advanceProgramCounter(4);
}

void CPU::_andi(uint32_t regs, uint32_t regt, uint16_t imm) {
    int32_t source = readRegister(regs);
    uint32_t result = source & (uint32_t)imm;
    writeRegister(regt, result);
    advanceProgramCounter(4);
}

void CPU::_beq(uint32_t regs, uint32_t regt, int16_t imm) {
    if (readRegister(regs) == readRegister(regt)) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_bgez(uint32_t regs, int16_t imm) {
    if ((int32_t)readRegister(regs) >= 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }

}

void CPU::_bgezal(uint32_t regs, int16_t imm) {
    writeRegister(31, getProgramCounter() + 8);
    if((int32_t)readRegister(regs) >= 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_bgtz(uint32_t regs, int16_t imm) {
    if ((int32_t)readRegister(regs) > 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_blez(uint32_t regs, int16_t imm) {
    if ((int32_t)readRegister(regs) <= 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_bltz(uint32_t regs, int16_t imm) {
    if ((int32_t)readRegister(regs) < 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_bltzal(uint32_t regs, int16_t imm) {
    writeRegister(31, getProgramCounter() + 8);
    if((int32_t)readRegister(regs) < 0) {
        advanceProgramCounter(imm << 2);
    } else {
        advanceProgramCounter(4);
    }
}

void CPU::_bne(uint32_t regs, uint32_t regt, int16_t imm) {
    if (readRegister(regs) != readRegister(regt)) {
        int32_t signExtImm = imm << 2;
        advanceProgramCounter(signExtImm);
    }else {
        advanceProgramCounter(4);
    }

}

void CPU::_div(uint32_t regs, uint32_t regt) {
    int32_t divider = readRegister(regt);
    if (divider == 0) {
        advanceProgramCounter(4);
        return;
    }
    writeLORegister((int32_t) readRegister(regs) / divider);
    writeHIRegister((int32_t) readRegister(regs) % divider);
    advanceProgramCounter(4);
}

void CPU::_divu(uint32_t regs, uint32_t regt) {
    uint32_t divider = readRegister(regt);
    if (divider == 0) {
        advanceProgramCounter(4);
        return;
    }
    writeLORegister(readRegister(regs) / divider);
    writeHIRegister(readRegister(regs) % divider);
    advanceProgramCounter(4);
}

void CPU::_j(uint32_t target) {
    uint32_t address = (getProgramCounter() & 0xF0000000) | (target << 2);
    setProgramCounter(address);
}

void CPU::_jal(uint32_t target) {
    writeRegister(31, getProgramCounter() + 8);
    uint32_t address = (getProgramCounter() & 0xF0000000) | (target << 2);
    setProgramCounter(address);
}

void CPU::_jalr(uint32_t regs, uint32_t regd) {
    writeRegister(regd, getProgramCounter() + 8);
    setProgramCounter(readRegister(regs));
}

void CPU::_jr(uint32_t regs) {
    setProgramCounter(readRegister(regs));
}

void CPU::_lb(uint32_t regs, uint32_t regt, int16_t imm) {
    int8_t data = memory->readByte(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, (int32_t)data);
    advanceProgramCounter(4);
}

void CPU::_lbu(uint32_t regs, uint32_t regt, int16_t imm) {
    uint32_t data = memory->readByte(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, data);
    advanceProgramCounter(4);
}

void CPU::_lh(uint32_t regs, uint32_t regt, int16_t imm) {
    int16_t data = memory->readHalfWord(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, (int32_t)data);
    advanceProgramCounter(4);
}

void CPU::_lhu(uint32_t regs, uint32_t regt, int16_t imm) {
    uint32_t data = memory->readHalfWord(readRegister(regs) + (int32_t)imm);
    writeRegister(regt, data);
    advanceProgramCounter(4);
}

void CPU::_lui(uint32_t regt, uint16_t imm) {
    writeRegister(regt, imm << 16);
    advanceProgramCounter(4);
}

void CPU::_lw(uint32_t regs, uint32_t regt, int16_t imm) {
    writeRegister(regt, memory->readWord(readRegister(regs) + imm));
    advanceProgramCounter(4);
}

void CPU::_lwl(uint32_t regs, uint32_t regt, int16_t imm) {
    uint32_t effAddr = readRegister(regs) + (int32_t) imm;
    uint32_t remainder = effAddr % 4;
    uint32_t mask = 0xFFFFFFFF >> (8 * (remainder));
    uint32_t resultMask;
    if(remainder == 0){
        resultMask = 0;
    } else {
        resultMask = 0xFFFFFFFF >> (8 * (4 - remainder));
    }
    uint32_t memData = memory->readWord(effAddr - remainder);
    uint32_t data = (memData & mask) << ((remainder) * 8);
    uint32_t storedData = readRegister(regt);
    uint32_t newData = (storedData & resultMask) | data;

    writeRegister(regt, newData);
    advanceProgramCounter(4);
}

void CPU::_lwr(uint32_t regs, uint32_t regt, int16_t imm) {

    uint32_t effAddr = (int32_t)readRegister(regs) + (int32_t) imm;
    uint32_t remainder = effAddr % 4;
    uint32_t mask = 0xFFFFFFFF << (8 * (3 - remainder));
    uint32_t resultMask;
    if(remainder == 3){
        resultMask = 0;
    } else {
        resultMask = 0xFFFFFFFF << (8 * (remainder + 1));
    }
    uint32_t memData = memory->readWord(effAddr - remainder);
    uint32_t data = (memData & mask) >> ((3- remainder) * 8);
    uint32_t storedData = readRegister(regt);
    uint32_t newData = (storedData & resultMask) | data;

    writeRegister(regt, newData);
    advanceProgramCounter(4);
}

void CPU::_mfhi(uint32_t regd) {
    writeRegister(regd, readHIRegister());
    advanceProgramCounter(4);
}

void CPU::_mflo(uint32_t regd) {
    writeRegister(regd, readLORegister());
    advanceProgramCounter(4);
}

void CPU::_mthi(uint32_t regs) {
    writeHIRegister(readRegister(regs));
    advanceProgramCounter(4);
}

void CPU::_mtlo(uint32_t regs) {
    writeLORegister(readRegister(regs));
    advanceProgramCounter(4);
}

void CPU::_mult(uint32_t regs, uint32_t regt) {
    int64_t sourceReg = (int32_t) readRegister(regs);
    int64_t otherSourceReg = (int32_t) readRegister(regt);
    int64_t result = (sourceReg * otherSourceReg);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
    advanceProgramCounter(4);
}

void CPU::_multu(uint32_t regs, uint32_t regt) {
    uint64_t result = (uint64_t)readRegister(regs) * (uint64_t)readRegister(regt);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
    advanceProgramCounter(4);
}

void CPU::_or(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) | readRegister(regt));
    advanceProgramCounter(4);
}

void CPU::_ori(uint32_t regs, uint32_t regt, uint16_t imm) {
    int32_t source = readRegister(regs);
    uint32_t result = source | imm;
    writeRegister(regt, result);
    advanceProgramCounter(4);
}

void CPU::_sb(uint32_t regs, uint32_t regt, int16_t imm) {
    memory->writeByte(readRegister(regs) + (int32_t)imm, readRegister(regt) & 0xFF);
    advanceProgramCounter(4);
}

void CPU::_sh(uint32_t regs, uint32_t regt, int16_t imm) {
    memory->writeHalfWord(readRegister(regs) + (int32_t)imm, (readRegister(regt) & 0x0000FFFF));
    advanceProgramCounter(4);
}

void CPU::_sll(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    writeRegister(regd, (readRegister(regs)) << shiftAmt);
    advanceProgramCounter(4);
}

void CPU::_sllv(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, (readRegister(regt)) << (readRegister(regs) & 0x1F));
    advanceProgramCounter(4);
}

void CPU::_slt(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t) readRegister(regs) < (int32_t) readRegister(regt)));
    advanceProgramCounter(4);
}

void CPU::_slti(uint32_t regs, uint32_t regd, int16_t imm) {
    writeRegister(regd, ((int32_t) readRegister(regs) < (int32_t)imm));
    advanceProgramCounter(4);
}

void CPU::_sltiu(uint32_t regs, uint32_t regd, int16_t imm) {
    int32_t signExt = imm;
    writeRegister(regd, (uint32_t) (readRegister(regs) < (uint32_t)signExt));
    advanceProgramCounter(4);
}

void CPU::_sltu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, (uint32_t) (readRegister(regs) < readRegister(regt)));
    advanceProgramCounter(4);
}

void CPU::_sra(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    writeRegister(regd, ((int32_t) readRegister(regs)) >> shiftAmt);
    advanceProgramCounter(4);
}

void CPU::_srav(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t) readRegister(regt)) >> (readRegister(regs) & 0x1F));
    advanceProgramCounter(4);
}

void CPU::_srl(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    writeRegister(regd, readRegister(regs) >> shiftAmt);
    advanceProgramCounter(4);
}

void CPU::_srlv(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regt) >> (readRegister(regs) & 0x1F));
    advanceProgramCounter(4);
}

void CPU::_sub(uint32_t regs, uint32_t regt, uint32_t regd) {
    int32_t sourceRegister = readRegister(regs);
    int32_t otherSourceRegister = readRegister(regt);
    int32_t result = sourceRegister - otherSourceRegister;

    if (((sourceRegister < 0 ) && (otherSourceRegister > 0) && (result >= 0)) ||
        ((sourceRegister > 0) && (otherSourceRegister < 0) && (result <= 0))) {
        exit(-10);
    }
    writeRegister(regd, result);
    advanceProgramCounter(4);
}

void CPU::_subu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, (int32_t)readRegister(regs) - (int32_t)readRegister(regt));
    advanceProgramCounter(4);
}

void CPU::_sw(uint32_t regs, uint32_t regt, int16_t imm) {
    memory->writeWord(readRegister(regs) + (int32_t)imm, readRegister(regt));
    advanceProgramCounter(4);
}

void CPU::_xor(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) ^ readRegister(regt));
    advanceProgramCounter(4);
}

void CPU::_xori(uint32_t regs, uint32_t regt, uint16_t imm) {
    uint32_t zeroExtImm = imm;
    writeRegister(regt, readRegister(regs) ^ zeroExtImm);
    advanceProgramCounter(4);
}
