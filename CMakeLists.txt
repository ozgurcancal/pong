cmake_minimum_required(VERSION 3.0)
project(pong)

set(CMAKE_CXX_STANDARD 20)
# Adjust the path to where SFML is located on your system
#set(SFML_INCLUDE_DIR "/opt/homebrew/Cellar/sfml/2.6.1/include")

include(FetchContent)
#FetchContent_Declare(SFML
#        GIT_REPOSITORY https://github.com/SFML/SFML.git
#        GIT_TAG 2.6.x)
#FetchContent_MakeAvailable(SFML)
#
# Set static if BUILD_STATIC is set
if (BUILD_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE)
    # Link libgcc and libstc++ statically as well
endif()

find_package( SFML 2.5.1 REQUIRED COMPONENTS graphics)
include_directories(${SFML_INCLUDE_DIR})
if(SFML_FOUND)
    #include_directories(${SFML_INCLUDE_DIR})
else()
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
    message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()
#include_directories(${SFML_DIR}/include)
#include_directories(${SFML_DIR}/lib)
#include_directories(${SFML_DIR}/lib/cmake/SFML)
#
set(HEADERS ${HEADERS}
	${PROJECT_SOURCE_DIR}/src/commands/command.h
    ${PROJECT_SOURCE_DIR}/src/commands/moveDown.h
    ${PROJECT_SOURCE_DIR}/src/commands/moveUp.h
    ${PROJECT_SOURCE_DIR}/src/inputHandler.h
    ${PROJECT_SOURCE_DIR}/src/commands/paddle.h
)

set(SOURCES ${SOURCES}
    ${PROJECT_SOURCE_DIR}/src/commands/moveDown.cpp
    ${PROJECT_SOURCE_DIR}/src/commands/moveUp.cpp
    ${PROJECT_SOURCE_DIR}/src/inputHandler.cpp
    ${PROJECT_SOURCE_DIR}/src/commands/paddle.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)
add_executable(pong ${HEADERS} ${SOURCES})

target_link_libraries(pong PUBLIC sfml-graphics)

#target_link_libraries(pong sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
