cmake_minimum_required(VERSION 3.10.2)

Project(Simulator)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")

#find_package(Boost)
#IF (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#endif()

include_directories(${PROJECT_SOURCE_DIR})
add_executable(simulator src/Simulator.cpp src/CPU/CPU.cpp src/CPU/CPU.h src/Instruction/Instruction.cpp src/Instruction/Instruction.h src/Instruction/RegisterInstruction.cpp src/Instruction/RegisterInstruction.h src/Instruction/JumpInstruction.cpp src/Instruction/JumpInstruction.h src/Instruction/ImmediateInstruction.cpp src/Instruction/ImmediateInstruction.h)
#target_link_libraries(simulator Boost)
