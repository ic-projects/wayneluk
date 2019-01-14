//
// Created by jordan on 04/11/18.
//

#ifndef SIMULATOR_MEMORY_H
#define SIMULATOR_MEMORY_H

#define ADDR_INSTR 0x10000000
#define ADDR_DATA 0x20000000
#define ADDR_PUTC 0x30000004
#define ADDR_GETC 0x30000000
#define SHIFT8 8
#define SHIFT16 16
#define SHIFT24 24
#define LOW8MASK  0x000000FF
#define SECOND8MASK 0x0000FF00
#define THIRD8MASK 0x00FF0000
#define LAST8MASK 0xFF000000

#define MEMERR -11

#include <cstdint>
#include <istream>

class Memory {
public:
    Memory(std::basic_istream<char>& binaryInput, size_t length);
    static size_t getSizeOfInstructionMemory();
    uint8_t readByte(uint32_t addr);
    uint32_t readWord(uint32_t addr);
    void writeByte(uint32_t addr, uint8_t byte);
    void writeWord(uint32_t addr, uint32_t word);
    uint16_t readHalfWord(uint32_t addr);
    void writeHalfWord(uint32_t addr, uint16_t halfword);
private:
    uint8_t instructionMemory[16777216] = {0};
    uint8_t dataMemory[67108864] = {0};
};

#endif //SIMULATOR_MEMORY_H
