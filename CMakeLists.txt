#[[CMake version]]
cmake_minimum_required(VERSION 3.14)
#[[Project Name]]
set(PROJECT_NAME BombermanC++)
project(${PROJECT_NAME})

#[[Using C++11]]
set(CMAKE_CXX_STANDARD 11)

#[[Nice setting to have when libs are gonna be mixed and linked together]]
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#[[Enable Testing]]
#enable_testing()

#[[Adding Google Test C++ Library]]
add_subdirectory(tests/libs/googletest)
include_directories(tests/libs/googletest/googletest/include)
include_directories(tests/libs/googletest/googlemock/include)

set( SDL_STATIC ON CACHE BOOL "" FORCE )
set( SDL_SHARED OFF CACHE BOOL "" FORCE )
add_subdirectory(libs/SDL2-2.0.9)

#[[Headers]]
set(Headers
        #Example.h
)

#[[Sources]]
set(Sources
        #Example.cpp
        src/main.cpp
        tests/tests.cpp tests/test_class.h src/Matrix.cpp src/Matrix.h src/Position.h src/GameObject.h src/Block.cpp src/Block.h src/Block.cpp src/Block.h src/GameBoard.cpp src/GameBoard.h)

add_executable(${PROJECT_NAME} ${Sources} ${Headers})
target_link_libraries(${PROJECT_NAME} gtest gtest_main SDL2main SDL2-static)


