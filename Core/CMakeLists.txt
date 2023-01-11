cmake_minimum_required(VERSION 3.13)


project(Core)

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES ${SRC_PATH}/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${SRC_PATH}/*.h)

source_group(TREE ${SRC_PATH} FILES ${PROJECT_SOURCES})
source_group(TREE ${SRC_PATH} FILES ${PROJECT_HEADERS})

add_library(Core SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})

set_property(TARGET Core PROPERTY CXX_STANDARD 11)

target_include_directories(Core PRIVATE ${STB_INCLUDE_DIRS} 
                                    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) 

target_link_libraries(Core PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> 
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
)

target_precompile_headers(Core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CorePCH.h)

if(WIN32)
    target_compile_definitions(Core PRIVATE GAME_CORE_WINDOWS  
                                        PRIVATE GAME_CORE_EXPORTS_DLL )
endif()

set_target_properties(Core PROPERTIES 
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

