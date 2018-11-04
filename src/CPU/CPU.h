//
// Created by jordan on 03/11/18.
//
#include <iostream>
#include <stdint.h>

#ifndef SIMULATOR_CPU_H
#define SIMULATOR_CPU_H

#define ADDR_INSTR 0x10000000
#define ADDR_DATA 0x20000000

class CPU {
public:
    CPU(std::basic_istream<char>& binaryInput, size_t length);

    uint8_t readByte(uint32_t addr);
    uint32_t readWord(uint32_t addr);

    void simulate();
    void halt();

private:
    bool shouldHalt = false;
    // Registers
    uint32_t programCounter = ADDR_INSTR;
    uint32_t registerFile[32] = {0};
    // Memory
    uint8_t instructionMemory[16777216] = {0};
    uint8_t dataMemory[67108864] = {0};
};

#endif //SIMULATOR_CPU_H
