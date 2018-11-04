//
// Created by jordan on 03/11/18.
//

#include <istream>
#include "CPU.h"
#include "Instruction.h"

CPU::CPU(Memory *memory) : memory(memory) {}

void CPU::simulate() {
    while (true) {
        int32_t  instruction = memory->readWord(programCounter);
        if (instruction == 0) {
            return;
        }
        executeInstruction(memory->readWord(programCounter));
        programCounter = programCounter + sizeof(uint32_t);
    }
}

uint32_t CPU::readRegister(uint32_t reg) {
    return registerFile[reg];
}

void CPU::writeRegister(uint32_t reg, uint32_t val) {
    registerFile[reg] = val;
}
