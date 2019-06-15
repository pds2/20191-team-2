#[[CMake version]]
cmake_minimum_required(VERSION 3.10)
#[[Project Name]]
set(PROJECT_NAME BombermanC++)
project(${PROJECT_NAME})

#[[Using C++11]]
set(CMAKE_CXX_STANDARD 11)

#[[Nice setting to have when libs are gonna be mixed and linked together]]
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#[[Adding Google Test C++ Library]]
add_subdirectory(tests/libs/googletest)
include_directories(tests/libs/googletest/googletest/include)
include_directories(tests/libs/googletest/googlemock/include)

# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

#[[Headers]]
set(Headers
        #Example.h
        tests/test_class.h
        src/Position.hpp
        src/Matrix.hpp
        src/GameBoard.hpp
        src/Game.hpp
        src/GameController.h
        src/GameObjectSDL.h
        src/TextureManager.hpp
        src/Block.h
        )

#[[Sources]]
set(Sources
        #Example.cpp
        src/main.cpp
        tests/tests.cpp
        src/Matrix.cpp
        src/Block.cpp
        src/GameBoard.cpp
        src/Game.cpp
        src/TextureManager.cpp
        src/GameObjectSDL.cpp
        src/Bomber.cpp src/Bomber.h src/ObjTypes.h tests/MatrixTests.cpp tests/PositionTests.cpp tests/TextureManagerTests.cpp tests/BomberTests.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${Sources} ${Headers})

#[[Linking Libraries]]
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
target_link_libraries(${PROJECT_NAME} gtest gtest_main SDL2::Main SDL2::Image)
