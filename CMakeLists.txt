cmake_minimum_required(VERSION 3.0)

Project(Simulator)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")

include_directories(${PROJECT_SOURCE_DIR})
add_executable(mips_simulator src/Simulator.cpp src/CPU.cpp src/CPU.h src/Instruction.h src/Memory.cpp src/Memory.h src/Instruction.cpp)
