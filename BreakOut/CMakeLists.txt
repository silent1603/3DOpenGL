cmake_minimum_required(VERSION 3.13)


project(BreakOut)



set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES ${SRC_PATH}/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${SRC_PATH}/*.h)
file(GLOB_RECURSE PROJECT_RESOURCES ${SRC_PATH}/Resources/*.*)

source_group(TREE ${SRC_PATH} FILES ${PROJECT_SOURCES})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_HEADERS})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_RESOURCES})

add_executable(BreakOut ${PROJECT_HEADERS} ${PROJECT_SOURCES})

set_property(TARGET BreakOut PROPERTY CXX_STANDARD 11)

target_include_directories(BreakOut PRIVATE ${STB_INCLUDE_DIRS} 
                                    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} 
                                    PRIVATE ${CMAKE_SOURCE_DIR}/Core) 

target_link_libraries(BreakOut          PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> 
                                        PRIVATE $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>  
                                        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static> 
                                        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static> 
                                        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static> 
                                        PRIVATE EnTT::EnTT 
                                        PRIVATE glad::glad 
                                        PRIVATE nlohmann_json nlohmann_json::nlohmann_json 
                                        PRIVATE spdlog::spdlog spdlog::spdlog_header_only 
                                        PRIVATE glm::glm  
                                        PRIVATE assimp::assimp
                                        PRIVATE ${BULLET_LIBRARIES}  
                                        PRIVATE Freetype::Freetype 
                                        PRIVATE OpenAL::OpenAL 
                                        PRIVATE EASTL  
                                        PRIVATE imgui::imgui
                                        PRIVATE Core 

)
add_custom_command(TARGET BreakOut POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory 
                      ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/Resources 
)
if(WIN32)
    target_compile_definitions(BreakOut PRIVATE GAME_CORE_WINDOWS PRIVATE GAME_CORE_IMPORTS_DLL)
   
endif()

target_precompile_headers(BreakOut PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GamePch.h)

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