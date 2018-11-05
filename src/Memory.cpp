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
        return (value >> (8 * (3 - (addr % 4))));
    }
    std::cerr << "Invalid simulated memory address (0x" << std::hex <<  addr << ") accessed" << std::endl;
    std::exit(-11);
}

uint32_t Memory::readWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {
        if (addr != ADDR_GETC) {
            std::exit(-11);
        }
        int32_t value = getchar();
        return value;
    }

    if (addr % 4 == 0) {
        uint32_t val = 0;
        for (uint i = 0; i < sizeof(uint32_t); i++) {
            // Read big-endian word, 8 bits at a time...
            val += readByte(addr + i) << (8 * (sizeof(uint32_t) - i - 1));
        }
        return val;
    }
    std::exit(-11);
}

void Memory::writeByte(uint32_t addr, uint8_t byte) {

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        int32_t shift = (byte  << (8*(3-(addr % 4))));
        int8_t res = shift & 0xFF;
        putchar(res);
        return;
    }

    if ((addr >= ADDR_DATA) && (addr < ADDR_DATA + sizeof(dataMemory))) {
        dataMemory[addr - ADDR_DATA] = byte;
        return;
    }

    std::cerr << "Attempted to write to invalid or read-only memory address (0x" << std::hex << addr << ")" << std::endl;
    std::exit(-11);
}

void Memory::writeWord(uint32_t addr, uint32_t word) {
    // Write big-endian word, 8 bits at a time

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        if (addr != ADDR_PUTC) {
            std::exit(-11);
        }
            int8_t res = word & 0xFF;
            putchar(res);
            return;
    }
    if (addr % 4 == 0) {
        writeByte(addr, (word & 0xFF000000) >> 24);
        writeByte(addr + 1, (word & 0x00FF0000) >> 16);
        writeByte(addr + 2, (word & 0x0000FF00) >> 8);
        writeByte(addr + 3, (word & 0x000000FF));
        return;
    }
    std::exit(-11);
}

uint16_t Memory::readHalfWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {

        if (addr % 2 == 0) {
            int32_t value = getchar();
            if (addr % 4 == 0) {
                return value >> 16;
            }
            return value;
        } else {
            std::exit(-11);
            //TODO - MEMORY LEAKS
        }
    }


    if(addr % 2 == 0) {
        uint16_t val = 0;
        for(uint i = 0; i < sizeof(uint16_t); i++) {
            val += readByte(addr+i) << (8 * (sizeof(uint32_t)) - i - 1);
        }
        return val;
    }
    std::exit(-11);

}

void Memory::writeHalfWord(uint32_t addr, uint16_t halfword) {

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        if (addr % 2 != 0) {
            std::exit(-11);
        }

        if (addr % 4 == 0) {
            int32_t shift = halfword << 16;
            int8_t res = shift & 0xFF;
            putchar(res);
            return;
        }
        //int res = (halfword  << (16*(1-(addr % 2))));
        int res = halfword & 0xFF;
        putchar(res);
        return;
    }

    if(addr % 2 == 0) {
        writeByte(addr, (halfword & 0x0000FF00) >> 8);
        writeByte(addr + 1, (halfword & 0x0000000FF));
        return;
    }
    std::exit(-11);
}
