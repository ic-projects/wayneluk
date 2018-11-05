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
        if (!(programCounter >= ADDR_INSTR && programCounter < ADDR_INSTR + Memory::getSizeOfInstructionMemory())) {
            std::cerr << "Attempted to execute non-executable memory address (0x" << std::hex <<  programCounter << ")" << std::endl;
            std::exit(-11);
        }
        executeInstruction(memory->readWord(programCounter));

    }
}

uint32_t CPU::readRegister(uint32_t reg) {
    return registerFile[reg];
}

void CPU::writeRegister(uint32_t reg, uint32_t val) {
    registerFile[reg] = val;
}

void CPU::advanceProgramCounter(int32_t offset) {
    programCounter = nextProgramCounter;
    nextProgramCounter = programCounter + offset;
}

void CPU::setProgramCounter(uint32_t address) {
    programCounter = nextProgramCounter;
    nextProgramCounter = address;
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
