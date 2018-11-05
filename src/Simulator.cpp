#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "CPU.h"

using namespace std;

int main (int argc, char *argv[]) {
    // Check args
    if (argc != 2) {
        cerr << "Usage: simulator <path to MIPS binary file>" << endl;
        exit(-20);
    }
    uint32_t val = -1;
    int32_t val1 = (int32_t) val;
    cout << val << " " << val1 << endl;
    // Try and load file
    ifstream binaryInput(argv[1], ios::in | ios::binary);
    if(binaryInput.fail()) {
        cerr << "The file " << argv[1] << " does not exist" << endl;
        exit(-20);
    }
    // Get the size
    binaryInput.seekg(0, ifstream::end);
    auto length = static_cast<size_t>(binaryInput.tellg());
    binaryInput.seekg(0, ifstream::beg);
    // Check for buffer overflow
    if (length > Memory::getSizeOfInstructionMemory()) {
        cerr << "The input file " << argv[1] << " is larger than the instruction memory" << endl;
        length = sizeof (Memory::getSizeOfInstructionMemory());
    }
    // Read binary into simulated instruction memory
    auto *memory = new Memory(binaryInput, length);
    // Create simulated CPU and begin simulation
    auto *cpu = new CPU(memory);
    cpu->simulate();

    for(auto i = 0; i < 32; i++) {
        cout << i << "    " << cpu->readRegister(i) << endl;
    }
    // Free memory and exit
    delete(memory);
    delete(cpu);
    exit(0);
}
