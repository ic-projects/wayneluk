//
// Created by jordan on 03/11/18.
//

#include <istream>
#include <src/Instruction/Instruction.h>
#include "CPU.h"

CPU::CPU(std::basic_istream<char>& binaryInput, size_t length) {
        binaryInput.read(reinterpret_cast<char*>(instructionMemory), length);
}

uint8_t CPU::readByte(uint32_t addr) {
    if ((addr >= ADDR_INSTR) && (addr < ADDR_INSTR + sizeof(instructionMemory))) {
        return instructionMemory[addr - ADDR_INSTR];
    }
    if ((addr >= ADDR_DATA) && (addr < ADDR_DATA + sizeof(dataMemory))) {
        return dataMemory[addr - ADDR_DATA];
    }
    return 0;
}

uint32_t CPU::readWord(uint32_t addr) {
    uint32_t val = 0;
    for (int i = 0; i < 4; i++) {
        val += readByte(addr + i) << (24 - 8 * i);
    }
    return val;
}

void CPU::simulate() {
    while (!shouldHalt) {
        InstructionDecoder::decodeInstruction(readWord(programCounter))->execute(this);
        programCounter = programCounter + sizeof(uint32_t);
    }
}

void CPU::halt() {
    shouldHalt = true;
}
