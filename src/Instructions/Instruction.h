//
// Created by jordan on 04/11/18.
//

#ifndef SIMULATOR_INSTRUCTION_H
#define SIMULATOR_INSTRUCTION_H

#include <cstdint>
#include "src/CPU.h"

// Helpers for decoding
#define OPCODE(instr) (instr >> 26)
#define REGS(instr) ((instr & 0x03E00000) >> 21)
#define REGT(instr) ((instr & 0x001F0000) >> 16)
#define TARGET(instr) (instr & 0x03FFFFFF)
#define IMM(instr) (instr & 0x0000FFFF)
#define REGD(instr) ((instr & 0x0000F800) >> 11)
#define SHIFTAMT(instr) ((instr & 0x000007C0) >> 6)
#define FNCODE(instr) (instr & 0x0000003F)


#define ARITHERR -10
// SHIFTS
#define SHIFT2 2

// 'R' instruction opcode
#define R 0b000000

// B_OTHER instruction opcodes
#define B_OTHER 0b000001

// 'B-Other' instruction regts
#define BGEZ 0b00001
#define BGEZAL 0b10001
#define BLTZ 0b00000
#define BLTZAL 0b10000

#endif //SIMULATOR_INSTRUCTION_H
