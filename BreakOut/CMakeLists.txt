cmake_minimum_required(VERSION 3.13)


project(BreakOut)


set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES ${SRC_PATH}/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${SRC_PATH}/*.h)
file(GLOB_RECURSE PROJECT_RESOURCES ${SRC_PATH}/Resources/*.*)

source_group(TREE ${SRC_PATH} FILES ${PROJECT_SOURCES})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_HEADERS})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_RESOURCES})

add_executable(BreakOut ${PROJECT_HEADERS} ${PROJECT_SOURCES})

set_property(TARGET BreakOut PROPERTY CXX_STANDARD 11)

target_include_directories(BreakOut  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} 
                                     PRIVATE ${CMAKE_SOURCE_DIR}/Core) 

target_link_libraries(BreakOut   PRIVATE spdlog::spdlog spdlog::spdlog_header_only 
                                 PRIVATE Core 

)
add_custom_command(TARGET BreakOut POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory 
                      ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_SOURCE_DIR}/bin/{PROJECT_NAME}/Resources 
)
if(WIN32)
target_compile_definitions(BreakOut PRIVATE GAME_CORE_WINDOWS PRIVATE GAME_CORE_IMPORTS_DLL)

endif()
set_target_properties(BreakOut PROPERTIES 
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib"
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/lib"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib" 
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/lib" 
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/lib" 
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" 
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin" 
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin" 

)