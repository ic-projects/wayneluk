//
// Created by jordan on 04/11/18.
//

#include <iostream>
#include "Memory.h"

Memory::Memory(std::basic_istream<char>& binaryInput, size_t length) {
    binaryInput.read(reinterpret_cast<char*>(instructionMemory), length);
}

size_t Memory::getSizeOfInstructionMemory() {
    return sizeof(instructionMemory);
}

uint8_t Memory::readByte(uint32_t addr) {
    if ((addr >= ADDR_INSTR) && (addr < ADDR_INSTR + sizeof(instructionMemory))) {
        return instructionMemory[addr - ADDR_INSTR];
    }
    if ((addr >= ADDR_DATA) && (addr < ADDR_DATA + sizeof(dataMemory))) {
        return dataMemory[addr - ADDR_DATA];
    }

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {
        int32_t value = getchar();
        return (value & (0xFF << 8 * (3 - (addr % 4))) >> (8*(3-(addr % 4))));
    }

    std::cerr << "Invalid simulated memory address (0x" << std::hex <<  addr << ") accessed" << std::endl;
    std::exit(-11);
}

uint32_t Memory::readWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {
        if(addr == ADDR_GETC) {
            int32_t value = getchar();
            return value;
        }
    }
    uint32_t val = 0;
    for (uint i = 0; i < sizeof(uint32_t); i++) {
        // Read big-endian word, 8 bits at a time...
        val += readByte(addr + i) << (8 * (sizeof(uint32_t) - i - 1));
    }
    return val;
}

void Memory::writeByte(uint32_t addr, uint8_t byte) {

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        int res = (byte  << (8*(3-(addr % 4))));
        putchar(res);
        return;
    }

    if ((addr >= ADDR_DATA) && (addr < ADDR_DATA + sizeof(dataMemory))) {
        dataMemory[addr - ADDR_DATA] = byte;
        return;
    }
    if (addr == ADDR_PUTC) {
        putchar(byte);
        return;
    }
    std::cerr << "Attempted to write to invalid or read-only memory address (0x" << std::hex << addr << ")" << std::endl;
    std::exit(-11);
}

void Memory::writeWord(uint32_t addr, uint32_t word) {
    // Write big-endian word, 8 bits at a time...
    writeByte(addr, (word & 0xFF000000) >> 24);
    writeByte(addr + 1, (word & 0x00FF0000) >> 16);
    writeByte(addr + 2, (word & 0x0000FF00) >> 8);
    writeByte(addr + 3, (word & 0x000000FF));
}

uint32_t Memory::readHalfWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {

        if (addr % 2 == 0) {
            int32_t value = getchar();
            return (value & (0xFFFF << 16 * (1 - (addr % 2))) >> (16*(1-(addr % 2))));
        } else {
            std::exit(-11);
            //TODO - MEMORY LEAKS
        }
    }

    uint16_t val = 0;
    for(uint i = 0; i < sizeof(uint16_t); i++) {
        val += readByte(addr+i) << (8 * (sizeof(uint32_t)) - i - 1);
    }
    return val;
}

void Memory::writeHalfWord(uint32_t addr, uint16_t halfword) {
    writeByte(addr, (halfword & 0x0000FF00) >> 8);
    writeByte(addr + 1, (halfword & 0x0000000FF));
}
