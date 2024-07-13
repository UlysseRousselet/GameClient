cmake_minimum_required(VERSION 3.5.0)
project(game_client VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "main.cpp" "src/*.cpp")
file(GLOB HEADERS "include/*.hpp" "include/asio/*.hpp")

add_executable(game_client ${SOURCES} ${HEADERS})

target_compile_options(game_client PRIVATE -Wall -Wextra)

target_link_libraries(game_client PRIVATE ws2_32)