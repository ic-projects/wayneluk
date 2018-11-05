//
// Created by jordan on 03/11/18.
//

#include <istream>
#include "CPU.h"
#include "Instruction.h"

CPU::CPU(Memory *memory) : memory(memory) {}

void CPU::simulate() {
    while (true) {
        if (programCounter == 0) {
            return;
        }
        executeInstruction(memory->readWord(programCounter));
        programCounter = programCounter + sizeof(uint32_t);
    }
}

uint32_t CPU::readRegister(uint32_t reg) {
    return registerFile[reg];
}

uint32_t CPU::getProgramCounter() {
    return programCounter;
}

void CPU::writeRegister(uint32_t reg, uint32_t val) {
    registerFile[reg] = val;
}

void CPU::setProgramCounter(uint32_t address) {
    programCounter = address;
}

uint32_t CPU::readHIRegister() {
    return HI;
}

void CPU::writeHIRegister(uint32_t val) {
    HI = val;
}

uint32_t CPU::readLORegister() {
    return LO;
}

void CPU::writeLORegister(uint32_t val) {
    LO = val;
}
