
cmake_minimum_required(VERSION 3.5)

project(unittest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(./src PROJECT_SOURCES)

link_directories(D:/devtools/googletest.mingw64.1.12.0/lib)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

INCLUDE_DIRECTORIES(
    D:/devtools/eigen.3.4.0/include/eigen3
    D:/devtools/googletest.mingw64.1.12.0/include
)

target_link_libraries(${PROJECT_NAME}  PRIVATE gtest)

file(COPY D:/devtools/googletest.mingw64.1.12.0/bin/libgtest.dll DESTINATION ./)
