cmake_minimum_required(VERSION 3.13)
#check is vcpkg is install
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

set(RELEASE_PATH "${PROJECT_SOURCE_DIR}/release")
set(DEBUG_PATH "${PROJECT_SOURCE_DIR}/debug")
project(GameOpenGL)

find_package(EASTL CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(Freetype REQUIRED)
find_package(Bullet CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenAL CONFIG REQUIRED) 
find_package(imgui CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")



set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

add_subdirectory(Core)
add_subdirectory(BreakOut)


if (MSVC) 
    set_target_properties(BreakOut PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${DEBUG_PATH}) 
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT BreakOut)
endif()