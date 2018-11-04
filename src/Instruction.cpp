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
            return addi(REGS(instruction), REGT(instruction), IMM(instruction));
        case ADDIU:
            return;
        case ANDI:
            return;
        case BEQ:
            return;
        case B_OTHER:
            return executeBranchInstruction(instruction);
        case BGTZ:
            return;
        case BLEZ:
            return;
        case BNE:
            return;
        case J:
            return;
        case JAL:
            return;
        case LB:
            return;
        case LBU:
            return;
        case LH:
            return;
        case LHU:
            return;
        case LUI:
            return lui(REGT(instruction), IMM(instruction));
        case LW:
            return;
        case LWL:
            return;
        case LWR:
            return;
        case ORI:
            return;
        case SB:
            return sb(REGS(instruction), REGT(instruction), IMM(instruction));
        case SH:
            return;
        case SLTI:
            return;
        case SLTIU:
            return;
        case SW:
            return sw(REGS(instruction), REGT(instruction), IMM(instruction));
        case XORI:
            return;
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::executeRInstruction(uint32_t instruction) {
    switch (FNCODE(instruction)) {
        case ADD:
            return;
        case ADDU:
            return;
        case AND:
            return;
        case DIV:
            return;
        case DIVU:
            return;
        case JALR:
            return;
        case JR:
            return;
        case MFHI:
            return;
        case MFLO:
            return;
        case MTHI:
            return;
        case MTLO:
            return;
        case MULT:
            return;
        case MULTU:
            return;
        case NOR:
            return;
        case OR:
            return;
        case SLL:
            return;
        case SLLV:
            return;
        case SLT:
            return;
        case SLTU:
            return;
        case SRA:
            return;
        case SRAV:
            return;
        case SRL:
            return;
        case SRLV:
            return;
        case SUB:
            return;
        case SUBU:
            return;
        case XOR:
            return;
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::executeBranchInstruction(uint32_t instruction) {
    switch (REGT(instruction)) {
        case BGEZ:
            return;
        case BGEZAL:
            return;
        case BLTZ:
            return;
        case BLTZAL:
            return;
        default:
            reportInvalidInstruction(instruction);
    }
}

void CPU::reportInvalidInstruction(uint32_t instruction) {
    std::cerr << "Attempted to execute invalid instruction (opcode: 0x" << std::hex << OPCODE(instruction) << ")" << std::endl;
    std::exit(-12);
}

void CPU::addi(uint32_t regs, uint32_t regt, uint32_t imm) {
    //TODO FIX ME
    writeRegister(regt, readRegister(regs) + imm);
}

void CPU::lui(uint32_t regt, uint32_t imm) {
    writeRegister(regt, imm << 16);
}

void CPU::sb(uint32_t regs, uint32_t regt, uint32_t imm) {
    memory->writeByte(readRegister(regs) + imm, readRegister(regt) & 0xFF);
}

void CPU::sw(uint32_t regs, uint32_t regt, uint32_t imm) {
    memory->writeWord(readRegister(regs) + imm, readRegister(regt));
}

void CPU::addu(uint32_t regs, uint32_t regst, uint32_t regsd) {
    writeRegister(regsd, readRegister(regs) + readRegister(regst));
}

void CPU::add(uint32_t regs, uint32_t regt, uint32_t regd) {
    int32_t sourceRegister = readRegister(regs);
    int32_t otherSourceRegister = readRegister(regt);
    int64_t result = sourceRegister + otherSourceRegister;
    int32_t otherResult = sourceRegister + otherSourceRegister;

    if (result != otherResult) {
        //TODO - FIX ME
        std::exit(-10);
    }

    writeRegister(regd, otherResult);

}

void CPU::addiu(uint32_t regs, uint32_t regt, int32_t signExtImm) {
    writeRegister(regt, readRegister(regs) + signExtImm);
}

void CPU::logicalAnd(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) & readRegister(regt));
}

void CPU::logicalAndI(uint32_t regs, uint32_t regt, int32_t zeroExtImm) {
    int32_t  source = readRegister(regs);
    uint32_t result = source & zeroExtImm;
    writeRegister(regt, result);
}


void CPU::jr(uint32_t regs) {
    setProgramCounter(readRegister(regs));
}

void CPU::lw(uint32_t regs, uint32_t regt, int32_t signExtImm) {
    writeRegister(regt, memory->readWord(readRegister(regs) + signExtImm));
}

void CPU::logicalOr(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) | readRegister(regt));
}

void CPU::logicalOrI(uint32_t regs, uint32_t regt, int32_t signExtImm) {
    int32_t  source = readRegister(regs);
    uint32_t result = source | signExtImm;
    writeRegister(regt, result);
}


void CPU::sh(uint32_t regs, uint32_t regt, int32_t signExtImm) {
    memory->writeHalfWord(readRegister(regs) + signExtImm, (readRegister(regt) & 0x0000FFFF));
}

void CPU::beq(uint32_t regs , uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::bgez(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::bgezal(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::bgtz(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::blez(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::jal(int32_t addr) {
    (void) addr;
}

void CPU::jalr(int32_t addr) {
    (void) addr;
}

void CPU::bltz(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::bltzal(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::bne(uint32_t regs, uint32_t regt, int32_t branchAddr) {
    (void) regs;
    (void) regt;
    (void)branchAddr;
}

void CPU::j(int32_t addr) {
    (void) addr;
}

void CPU::lb(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t data = memory->readByte(regs + imm);
    writeRegister(regt, data);
}

void CPU::lbu(uint32_t regs, uint32_t regt, int32_t imm) {
    uint32_t data = memory->readByte(regs + imm);
    writeRegister(regt, data);
}

void CPU::lh(uint32_t regs, uint32_t regt, int32_t imm) {
    int32_t data = memory->readHalfWord(regs + imm);
    writeRegister(regt, data);
}

void CPU::lhu(uint32_t regs, uint32_t regt, int32_t imm) {
    uint32_t data = memory->readHalfWord(regs + imm);
    writeRegister(regt, data);
}

void CPU::lwl(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void)imm;
}

void CPU::lwr(uint32_t regs, uint32_t regt, int32_t imm) {
    (void) regs;
    (void) regt;
    (void)imm;
}

void CPU::logicalXorI(uint32_t regs, uint32_t regt, uint32_t imm) {
    writeRegister(regt, readRegister(regs) ^ imm);
}

void CPU::logicalXor(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) ^ readRegister(regt));
}

void CPU::subu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, regs - regt);
}

void CPU::sub(uint32_t regs, uint32_t regt, uint32_t regd) {
    //TODO FIX ME - OVERFLOW
    writeRegister(regd, regs - regt);
}

void CPU::srlv(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, readRegister(regs) >> (readRegister(regt) & 0x0000000F));
}

void CPU::srl(uint32_t regs, uint32_t regd, uint32_t shift) {
    writeRegister(regd, readRegister(regs) >> shift);
}

void CPU::srav(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t)readRegister(regs)) >> (readRegister(regt) & 0x0000000F));
}

void CPU::sra(uint32_t regs, uint32_t regd, uint32_t shift) {
    writeRegister(regd, ((int32_t)readRegister(regs)) >> shift);
}

void CPU::sltu(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, (uint32_t)(readRegister(regs) < readRegister(regt)));
}

void CPU::sltiu(uint32_t regs, uint32_t regd, uint32_t constant) {
    writeRegister(regd, (uint32_t)(readRegister(regs) < constant));
}

void CPU::slti(uint32_t regs, uint32_t regd, int32_t constant) {
    writeRegister(regd, ((int32_t)readRegister(regs) < constant));
}

void CPU::slt(uint32_t regs, uint32_t regt, uint32_t regd) {
    writeRegister(regd, ((int32_t)readRegister(regs) < (int32_t)readRegister(regt)));
}

void CPU::sllv(uint32_t regs, uint32_t regt, uint32_t regd) {
    //TODO FIX ME - OVERFLOW??? - Prob not
    writeRegister(regd, ((int32_t)readRegister(regs)) << (readRegister(regt) & 0x0000000F));
}

void CPU::sll(uint32_t regs, uint32_t regd, uint32_t shift) {
    //TODO FIX ME - OVERFLOW???? - Prob not
    writeRegister(regd, ((int32_t)readRegister(regs)) << shift);
}

void CPU::multu(uint32_t regs, uint32_t regt) {
    uint64_t result = readRegister(regs) * readRegister(regt);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
}

void CPU::mult(uint32_t regs, uint32_t regt) {
    int64_t result = (int32_t)readRegister(regs) * (int32_t)readRegister(regt);
    writeHIRegister((result & 0xFFFFFFFF00000000) >> 32);
    writeLORegister((result & 0x00000000FFFFFFFF));
}

void CPU::mtlo(uint32_t regs) {
    writeLORegister(regs);
}

void CPU::mthi(uint32_t regs) {
    writeHIRegister(regs);
}

void CPU::mflo(uint32_t regd) {
    writeRegister(regd, readLORegister());
}

void CPU::mfhi(uint32_t regd) {
    writeRegister(regd, readHIRegister());
}

void CPU::div(uint32_t regs, uint32_t regt) {
    writeLORegister((int32_t) readRegister(regs) / (int32_t) readRegister(regt));
    writeHIRegister((int32_t) readRegister(regs) % (int32_t) readRegister(regt));
}

void CPU::divu(uint32_t regs, uint32_t regt) {
    writeLORegister(readRegister(regs) / readRegister(regt));
    writeHIRegister(readRegister(regs) % readRegister(regt));
}