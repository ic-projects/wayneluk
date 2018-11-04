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
add_executable(simulator src/Simulator.cpp src/CPU.cpp src/CPU.h src/Instruction.h src/Memory.cpp src/Memory.h src/Instruction.cpp)
#target_link_libraries(simulator Boost)
