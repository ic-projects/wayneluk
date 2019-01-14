//
// Created by jordan on 03/11/18.
//

#include <istream>
#include "CPU.h"
#include "src/Instructions/Instruction.h"

CPU::CPU(Memory *memory) : memory(memory) {}

void CPU::simulate() {
    while (true) {
        if (programCounter == 0) {
            return;
        }
        if (!(programCounter >= ADDR_INSTR && programCounter < ADDR_INSTR + Memory::getSizeOfInstructionMemory())) {
            std::cerr << "Attempted to execute non-executable memory address (0x" << std::hex <<  programCounter << ")" << std::endl;
            std::exit(CPUERR);
        }
        executeInstruction(memory->readWord(programCounter));
        if(updatePC) {
            advanceProgramCounter(PC_INC);
        }
        updatePC = true;
    }
}

// Read the value in GPR
uint32_t CPU::readRegister(uint32_t reg) {
    return registerFile[reg];
}

// Write the value to GPR
void CPU::writeRegister(uint32_t reg, uint32_t val) {
    registerFile[reg] = val;
}

// Increment Program counter by offset
void CPU::advanceProgramCounter(int32_t offset) {
    programCounter = nextProgramCounter;
    nextProgramCounter = programCounter + offset;
}

// Set the program counter to an address
void CPU::setProgramCounter(uint32_t address) {
    programCounter = nextProgramCounter;
    nextProgramCounter = address;
}

// Return the program counter
uint32_t CPU::getProgramCounter() {
    return programCounter;
}

// Read the HIGH Register
uint32_t CPU::readHIRegister() {
    return HI;
}

// Write to the LOW Register
void CPU::writeHIRegister(uint32_t val) {
    HI = val;
}

// Read the Low Register
uint32_t CPU::readLORegister() {
    return LO;
}

// Write to the Low Register
void CPU::writeLORegister(uint32_t val) {
    LO = val;
}
