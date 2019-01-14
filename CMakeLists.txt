cmake_minimum_required(VERSION 3.0)

Project(Simulator)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")

include_directories(${PROJECT_SOURCE_DIR})
add_executable(simulator src/Simulator.cpp src/CPU.cpp src/CPU.h src/Instructions/Instruction.h src/Memory.cpp src/Memory.h src/Instructions/Instruction.cpp src/Instructions/RTypeInstruction.cpp src/Instructions/RTypeInstruction.h src/Instructions/ITypeInstruction.cpp src/Instructions/ITypeInstruction.h src/Instructions/JTypeInstruction.cpp src/Instructions/JTypeInstruction.h)
