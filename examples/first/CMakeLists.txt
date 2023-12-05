
cmake_minimum_required(VERSION 3.5)

project(first VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(./ PROJECT_SOURCES)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})


INCLUDE_DIRECTORIES(
    D:/devtools/eigen.3.4.0/include/eigen3
)
