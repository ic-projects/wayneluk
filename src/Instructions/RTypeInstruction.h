//
// Created by pranav on 1/13/19.
//

#ifndef SIMULATOR_RTYPEINSTRUCTION_H
#define SIMULATOR_RTYPEINSTRUCTION_H


//Bit Masks
#define FIVEBITS 0x1F
#define HIGHMASK 0xFFFFFFFF00000000
#define LOMASK 0x00000000FFFFFFFF
#define SHIFT32 32

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

#endif //SIMULATOR_RTYPEINSTRUCTION_H
