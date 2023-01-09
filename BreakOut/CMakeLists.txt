cmake_minimum_required(VERSION 3.13)


project(BreakOut)


set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES ${SRC_PATH}/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${SRC_PATH}/*.h)

source_group(TREE ${SRC_PATH} FILES ${PROJECT_SOURCES})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_HEADERS})

add_library(BreakOut SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

set_property(TARGET BreakOut PROPERTY CXX_STANDARD 11)

target_include_directories(BreakOut  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) 

target_link_libraries(BreakOut   PRIVATE spdlog::spdlog spdlog::spdlog_header_only 
                                 PRIVATE Core 

)


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