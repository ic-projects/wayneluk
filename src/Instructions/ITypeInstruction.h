//
// Created by pranav on 1/13/19.
//

#ifndef SIMULATOR_ITYPEINSTRUCTION_H
#define SIMULATOR_ITYPEINSTRUCTION_H


// Bit Shift
#define FIRST16 0x0000FFFF
#define FIRST8 0xFF
#define ALLBITS 0xFFFFFFFF
#define SHIFT16 16

// 'I' instruction opcodes
#define ADDI 0b001000
#define ADDIU 0b001001
#define ANDI 0b001100
#define BEQ 0b000100
#define BGTZ 0b000111
#define BLEZ 0b000110
#define BNE 0b000101
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


#endif //SIMULATOR_ITYPEINSTRUCTION_H
