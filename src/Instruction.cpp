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
