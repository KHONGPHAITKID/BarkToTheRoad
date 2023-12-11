cmake_minimum_required(VERSION 3.5)

project(Bark)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB Bark_SRC
     "*.h"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${Bark_SRC})