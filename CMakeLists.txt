cmake_minimum_required(VERSION 3.10)
project(tbx_utils)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES "src/*.cpp")
# Add the main executable
add_executable(${PROJECT_NAME} ${SOURCES})


set(GENERATED_META_PROGRAM_HEADER "${CMAKE_SOURCE_DIR}/src/meta_program/meta_program.hpp")

if(EXISTS "${GENERATED_META_PROGRAM_HEADER}" AND NOT IS_DIRECTORY "${GENERATED_META_PROGRAM_HEADER}")
    message(STATUS "Found generated meta_program.hpp, enabling GENERATED_META_PROGRAM")
    target_compile_definitions(${PROJECT_NAME} PRIVATE GENERATED_META_PROGRAM)
endif()

        
find_package(fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
