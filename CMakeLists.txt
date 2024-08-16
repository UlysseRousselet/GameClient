cmake_minimum_required(VERSION 3.5.0)
project(game_client VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(RAYLIB_DIR ${PROJECT_SOURCE_DIR}/include/raylib)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.zip
    FIND_PACKAGE_ARGS 5.0
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${RAYLIB_DIR}/include
)

file(GLOB SOURCES "src/*.cpp" "src/client/*.cpp" "src/asio/*.cpp" "src/client/command/*.cpp" 
"src/graphic/*.cpp" "src/graphic/render/*.cpp" "src/graphic/settings/*.cpp")
# file(GLOB HEADERS "include/*.hpp" "include/graphic/*.hpp")

add_executable(game_client ${SOURCES} ${HEADERS})

target_compile_options(game_client PRIVATE -Wall -Wextra 
$<$<CXX_COMPILER_ID:GNU>:-Wno-missing-field-initializers>
$<$<CXX_COMPILER_ID:Clang>:-Wno-missing-field-initializers>)

target_link_libraries(${PROJECT_NAME} raylib)

if (WIN32)
    target_link_libraries(game_client ws2_32)
endif()

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${RAYLIB_DIR}/lib/raylib.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()