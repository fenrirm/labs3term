cmake_minimum_required(VERSION 3.17)
project(lab3term_3)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR D:/libr/SDL/include)
set(SDL2_LIB_DIR D:/libr/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(SOURCE_FILES main.cpp)
add_executable(lab3term_3 main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)