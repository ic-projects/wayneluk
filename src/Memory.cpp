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

// Check if address is valid and read a byte from memory.
// If address is in range for IO input, stall and get the value.
// IMPLEMENTATION DEPENDANT - READING byte from IO input is not properly defined.
// In this implementation - get the value from IO and shift to get the correct byte we want based on the address.
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
    std::cerr << "Attempted to read from non-readable memory address (0x" << std::hex <<  addr << ")" << std::endl;
    std::exit(MEMERR);
}

// READ word from memory.
// IF address points to IO MEM READ range then stall and get value from input.
uint32_t Memory::readWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {
        if (addr != ADDR_GETC) {
            std::exit(MEMERR);
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
    std::exit(MEMERR);
}

// Check if address is valid and write byte to memory.
// If address is in range for IO output, stall and put the value.
// IMPLEMENTATION DEPENDANT - WRITING byte to IO output is not properly defined.
// In this implementation - put the byte the address is pointing to, to the IO Output.
void Memory::writeByte(uint32_t addr, uint8_t byte) {

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        int32_t shift = (byte  << (8*(3-(addr % 4))));
        int8_t res = shift & LOW8MASK;
        putchar(res);
        return;
    }

    if ((addr >= ADDR_DATA) && (addr < ADDR_DATA + sizeof(dataMemory))) {
        dataMemory[addr - ADDR_DATA] = byte;
        return;
    }

    std::cerr << "Attempted to write to non-writeable memory address (0x" << std::hex << addr << ")" << std::endl;
    std::exit(MEMERR);
}

// Write word to memory
// IF address points to IO MEM WRITE range then stall and put value to std out.
void Memory::writeWord(uint32_t addr, uint32_t word) {
    // Write big-endian word, 8 bits at a time

    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        if (addr != ADDR_PUTC) {
            std::exit(MEMERR);
        }
            int8_t res = word & LOW8MASK;
            putchar(res);
            return;
    }
    if (addr % 4 == 0) {
        writeByte(addr, (word & LAST8MASK) >> SHIFT24);
        writeByte(addr + 1, (word & THIRD8MASK) >> SHIFT16);
        writeByte(addr + 2, (word & SECOND8MASK) >> SHIFT8);
        writeByte(addr + 3, (word & LOW8MASK));
        return;
    }
    std::exit(MEMERR);
}


// Check if address is valid and alligned, then read a halfword from memory.
// If address is in range for IO input, stall and get the value.
// IMPLEMENTATION DEPENDANT - READING halfword from IO input is not properly defined.
// In this implementation - get the value from IO and shift to get the correct halfword we want based on the address.
uint16_t Memory::readHalfWord(uint32_t addr) {

    if((addr >= ADDR_GETC) && (addr < ADDR_GETC + 4)) {

        if (addr % 2 == 0) {
            int32_t value = getchar();
            if (addr % 4 == 0) {
                return value >> SHIFT16;
            }
            return value;
        } else {
            std::exit(MEMERR);
        }
    }


    if(addr % 2 == 0) {
        uint16_t val = 0;
        for(uint i = 0; i < sizeof(uint16_t); i++) {
            val += (readByte(addr+i) << (8 * (sizeof(uint16_t) - i - 1)));
        }
        return val;
    }
    std::exit(MEMERR);


}

// Check if address is valid and alligned then write halfword to memory.
// If address is in range for IO output, stall and put the value.
// IMPLEMENTATION DEPENDANT - WRITING halfword to IO output is not properly defined.
// In this implementation - put the halfword based on the address to the IO Output.
void Memory::writeHalfWord(uint32_t addr, uint16_t halfword) {
    if ((addr >= ADDR_PUTC) && (addr < ADDR_PUTC + 4)) {
        if (addr % 2 != 0) {
            std::exit(MEMERR);
        }

        if (addr % 4 == 0) {
            int32_t shift = halfword << SHIFT16;
            int8_t res = shift & LOW8MASK;
            putchar(res);
            return;
        }
        int res = halfword & LOW8MASK;
        putchar(res);
        return;
    }

    if(addr % 2 == 0) {
        writeByte(addr, (halfword & SECOND8MASK) >> SHIFT8);
        writeByte(addr + 1, (halfword & LOW8MASK));
        return;
    }
    std::exit(MEMERR);
}
