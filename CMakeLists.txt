cmake_minimum_required(VERSION 3.0)
project(pong)

set(CMAKE_CXX_STANDARD 20)

if (BUILD_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package( SFML 2.5.1 REQUIRED COMPONENTS graphics)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
    message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

include_directories(${PROJECT_SOURCE_DIR}/src/gameObjects)

set(HEADERS ${HEADERS}
	${PROJECT_SOURCE_DIR}/src/commands/command.h
    ${PROJECT_SOURCE_DIR}/src/commands/moveDown.h
    ${PROJECT_SOURCE_DIR}/src/commands/moveUp.h

    ${PROJECT_SOURCE_DIR}/src/gameObjects/gameObjectFactory.h
    ${PROJECT_SOURCE_DIR}/src/gameObjects/paddle.h
    ${PROJECT_SOURCE_DIR}/src/gameObjects/ball.h

    ${PROJECT_SOURCE_DIR}/src/gameController.h
    ${PROJECT_SOURCE_DIR}/src/commandHandler.h
)

set(SOURCES ${SOURCES}
    ${PROJECT_SOURCE_DIR}/src/commands/moveDown.cpp
    ${PROJECT_SOURCE_DIR}/src/commands/moveUp.cpp

    ${PROJECT_SOURCE_DIR}/src/gameObjects/gameObjectFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/gameObjects/paddle.cpp
    ${PROJECT_SOURCE_DIR}/src/gameObjects/ball.cpp

    ${PROJECT_SOURCE_DIR}/src/gameController.cpp
    ${PROJECT_SOURCE_DIR}/src/commandHandler.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(pong ${HEADERS} ${SOURCES})

target_link_libraries(pong PUBLIC sfml-graphics)
