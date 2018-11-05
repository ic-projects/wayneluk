//
// Created by jordan on 04/11/18.
//

#ifndef SIMULATOR_INSTRUCTION_H
#define SIMULATOR_INSTRUCTION_H

#include <cstdint>

// Helpers for decoding
#define OPCODE(instr) (instr >> 26)
#define REGS(instr) ((instr & 0x03E00000) >> 21)
#define REGT(instr) ((instr & 0x001F0000) >> 16)
#define TARGET(instr) (instr & 0x03FFFFFF)
#define IMM(instr) (instr & 0x0000FFFF)
#define REGD(instr) ((instr & 0x0000F800) >> 11)
#define SHIFTAMT(instr) ((instr & 0x000007C0) >> 6)
#define FNCODE(instr) (instr & 0x0000003F)

// 'R' instruction opcode
#define R 0b000000

// 'R' instruction function codes
#define ADD 0b100000
#define ADDU 0b100001
#define AND 0b100100
#define DIV 0b011010
#define DIVU 0b011011
#define JALR 0b001001
#define JR 0b001000
#define MFHI 0b010000
#define MFLO 0b010010
#define MTHI 0b010001
#define MTLO 0b010011
#define MULT 0b011000
#define MULTU 0b011001
#define OR 0b100101
#define SLL 0b000000
#define SLLV 0b000100
#define SLT 0b101010
#define SLTU 0b101011
#define SRA 0b000011
#define SRAV 0b000111
#define SRL 0b000010
#define SRLV 0b000110
#define SUB 0b100010
#define SUBU 0b100011
#define XOR 0b100110

// 'J' instruction opcodes
#define J 0b000010
#define JAL 0b000011

// 'I' instruction opcodes
#define ADDI 0b001000
#define ADDIU 0b001001
#define ANDI 0b001100
#define BEQ 0b000100
#define BGTZ 0b000111
#define BLEZ 0b000110
#define BNE 0b000101
#define B_OTHER 0b000001
#define LB 0b100000
#define LBU 0b100100
#define LH 0b100001
#define LHU 0b100101
#define LUI 0b001111
#define LW 0b100011
#define LWL 0b100010
#define LWR 0b100110
#define ORI 0b001101
#define SB 0b101000
#define SH 0b101001
#define SLTI 0b001010
#define SLTIU 0b001011
#define SW 0b101011
#define XORI 0b001110

// 'B-Other' instruction regts
#define BGEZ 0b00001
#define BGEZAL 0b10001
#define BLTZ 0b00000
#define BLTZAL 0b10000

#endif //SIMULATOR_INSTRUCTION_H
