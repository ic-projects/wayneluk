//
// Created by jordan on 04/11/18.
//

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
            return _bgtz(REGS(instruction), REGT(instruction), IMM(instruction));
        case BLEZ:
            return _blez(REGS(instruction), REGT(instruction), IMM(instruction));
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
            return _mfhi(REGS(instruction));
        case MFLO:
            return _mflo(REGS(instruction));
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
            return _sll(REGS(instruction), REGT(instruction), SHIFTAMT(instruction));
        case SLLV:
            return _sllv(REGS(instruction), REGT(instruction), REGD(instruction));
        case SLT:
            return _slt(REGS(instruction), REGT(instruction), REGD(instruction));
        case SLTU:
            return _sltu(REGS(instruction), REGT(instruction), REGD(instruction));
        case SRA:
            return _sra(REGS(instruction), REGT(instruction), SHIFTAMT(instruction));
        case SRAV:
            return _srav(REGS(instruction), REGT(instruction), REGD(instruction));
        case SRL:
            return _srl(REGS(instruction), REGT(instruction), SHIFTAMT(instruction));
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
            return _bgez(REGS(instruction), REGT(instruction), IMM(instruction));
        case BGEZAL:
            return _bgezal(REGS(instruction), REGT(instruction), IMM(instruction));
        case BLTZ:
            return _bltz(REGS(instruction), REGT(instruction), IMM(instruction));
        case BLTZAL:
            return _bltzal(REGS(instruction), REGT(instruction), IMM(instruction));
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
    int32_t sourceRegister = readRegister(regs);
    int32_t otherSourceRegister = readRegister(regt);
    int64_t result = sourceRegister + otherSourceRegister;
    int32_t otherResult = sourceRegister + otherSourceRegister;

    if (result != otherResult) {
        //TODO - FIX ME
        std::exit(-10);
    }
    writeRegister(regd, otherResult);
    std::cout << regs << " " << regt << " " << regd << std::endl;
    std::cout << readRegister(regs) <<  "  " << readRegister(regt) << "  "  << "  " << otherResult << readRegister(regd) << std::endl;
}

void CPU::_addi(uint32_t regs, uint32_t regt, uint32_t imm) {
    //TODO FIX ME - Overflow
    int32_t source = (int32_t)readRegister(regs);
    int32_t constant = (int16_t)imm;

    std::cout << source << " " << constant << std::endl;
    if ((source < 0 && constant < 0 && ((int32_t) (source + constant) > 0)) ||
        (source > 0 && constant > 0 && ((int32_t) (source + constant) < 0))) {
        std::exit(-10);
    }
    writeRegister(regt, (int32_t) (source + constant));
}

void CPU::_addiu(uint32_t regs, uint32_t regt, int32_t imm) {
    std::cout << "I'm HERE1" << std::endl;
    writeRegister(regt, readRegister(regs) + imm);
}

void CPU::_addu(uint32_t regs, uint32_t regst, uint32_t regsd) {
    std::cout << "I'm HERE" << std::endl;
    writeRegister(regsd, readRegister(regs) + readRegister(regst));
}

void CPU::_and(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) & readRegister(regt));
}

void CPU::_andi(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t source = readRegister(regs);
    uint32_t result = source & imm;
    writeRegister(regt, result);
}

void CPU::_beq(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bgez(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bgezal(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bgtz(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_blez(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bltz(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bltzal(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_bne(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_div(uint32_t regs, uint32_t regt) {
    writeLORegister((int32_t) readRegister(regs) / (int32_t) readRegister(regt));
    writeHIRegister((int32_t) readRegister(regs) % (int32_t) readRegister(regt));
}

void CPU::_divu(uint32_t regs, uint32_t regt) {
    writeLORegister(readRegister(regs) / readRegister(regt));
    writeHIRegister(readRegister(regs) % readRegister(regt));
}

void CPU::_j(int32_t target) {
    (void) target;
}

void CPU::_jal(int32_t target) {
    (void) target;
}

void CPU::_jalr(uint32_t regs, uint32_t regd) {
    (void) regs;
    (void) regd;
}

void CPU::_jr(uint32_t regs) {
    setProgramCounter(readRegister(regs) - 4);
}

void CPU::_lb(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t data = memory->readByte(readRegister(regs) + imm);
    writeRegister(regt, data);
}

void CPU::_lbu(uint32_t regs, uint32_t regt, int32_t imm) {
    uint32_t data = memory->readByte(readRegister(regs) + imm);
    writeRegister(regt, data);
}

void CPU::_lh(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t data = memory->readHalfWord(readRegister(regs) + imm);
    writeRegister(regt, data);
}

void CPU::_lhu(uint32_t regs, uint32_t regt, int32_t imm) {
    uint32_t data = memory->readHalfWord(readRegister(regs) + imm);
    writeRegister(regt, data);
}

void CPU::_lui(uint32_t regt, uint32_t imm) {
    writeRegister(regt, imm << 16);
}

void CPU::_lw(uint32_t regs, uint32_t regt, int32_t imm) {
    writeRegister(regt, memory->readWord(readRegister(regs) + imm));
}

void CPU::_lwl(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_lwr(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void) imm;
}

void CPU::_mfhi(uint32_t regd) {
    writeRegister(regd, readHIRegister());
}

void CPU::_mflo(uint32_t regd) {
    writeRegister(regd, readLORegister());
}

void CPU::_mthi(uint32_t regs) {
    writeHIRegister(regs);
}

void CPU::_mtlo(uint32_t regs) {
    writeLORegister(regs);
}

void CPU::_mult(uint32_t regs, uint32_t regt) {
    int64_t result = (int32_t) readRegister(regs) * (int32_t) readRegister(regt);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
}

void CPU::_multu(uint32_t regs, uint32_t regt) {
    uint64_t result = readRegister(regs) * readRegister(regt);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
}

void CPU::_or(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) | readRegister(regt));
}

void CPU::_ori(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t source = readRegister(regs);
    uint32_t result = source | imm;
    writeRegister(regt, result);
}

void CPU::_sb(uint32_t regs, uint32_t regt, uint32_t imm) {
    memory->writeByte(readRegister(regs) + imm, readRegister(regt) & 0xFF);
}

void CPU::_sh(uint32_t regs, uint32_t regt, int32_t imm) {
    memory->writeHalfWord(readRegister(regs) + imm, (readRegister(regt) & 0x0000FFFF));
}

void CPU::_sll(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    //TODO FIX ME - OVERFLOW???? - Prob not
    writeRegister(regd, ((int32_t) readRegister(regs)) << shiftAmt);
}

void CPU::_sllv(uint32_t regs, uint32_t regt, uint32_t regd) {
    //TODO FIX ME - OVERFLOW??? - Prob not
    writeRegister(regd, ((int32_t) readRegister(regs)) << (readRegister(regt) & 0x0000000F));
}

void CPU::_slt(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t) readRegister(regs) < (int32_t) readRegister(regt)));
}

void CPU::_slti(uint32_t regs, uint32_t regd, int32_t imm) {
    writeRegister(regd, ((int32_t) readRegister(regs) < imm));
}

void CPU::_sltiu(uint32_t regs, uint32_t regd, uint32_t imm) {
    writeRegister(regd, (uint32_t) (readRegister(regs) < imm));
}

void CPU::_sltu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, (uint32_t) (readRegister(regs) < readRegister(regt)));
}

void CPU::_sra(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    writeRegister(regd, ((int32_t) readRegister(regs)) >> shiftAmt);
}

void CPU::_srav(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t) readRegister(regs)) >> (readRegister(regt) & 0x0000000F));
}

void CPU::_srl(uint32_t regs, uint32_t regd, uint32_t shiftAmt) {
    writeRegister(regd, readRegister(regs) >> shiftAmt);
}

void CPU::_srlv(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) >> (readRegister(regt) & 0x0000000F));
}

void CPU::_sub(uint32_t regs, uint32_t regt, uint32_t regd) {
    //TODO FIX ME - OVERFLOW
    writeRegister(regd, regs - regt);
}

void CPU::_subu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, regs - regt);
}

void CPU::_sw(uint32_t regs, uint32_t regt, uint32_t imm) {
    memory->writeWord(readRegister(regs) + imm, readRegister(regt));
}

void CPU::_xor(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) ^ readRegister(regt));
}

void CPU::_xori(uint32_t regs, uint32_t regt, uint32_t imm) {
    writeRegister(regt, readRegister(regs) ^ imm);
}
