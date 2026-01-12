cmake_minimum_required(VERSION 3.16)
project(osu-map-fuser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C++ standard
add_compile_options(-std=c++23)

# Collect sources from src/ and root
file(GLOB_RECURSE SRC_FILES
    # // "${CMAKE_SOURCE_DIR}/src/pch.h"
    # // "${CMAKE_SOURCE_DIR}/src/debug/debug.h"
    
    # // "${CMAKE_SOURCE_DIR}/src/audioengine_config_override.cpp
    
    # // "${CMAKE_SOURCE_DIR}/src/core/*.cpp"
    # // "${CMAKE_SOURCE_DIR}/src/debug/*.cpp"
    # // "${CMAKE_SOURCE_DIR}/src/state/*.cpp"
    # // "${CMAKE_SOURCE_DIR}/src/rendering/*.cpp"
    # // "${CMAKE_SOURCE_DIR}/src/audio/*.cpp"

    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

# Exclude external libraries
list(FILTER SRC_FILES EXCLUDE REGEX "3rd-party/osu-parser/.*")
list(FILTER SRC_FILES EXCLUDE REGEX "3rd-party/osuReplayEditorV3/.*")
# // list(FILTER SRC_FILES EXCLUDE REGEX "src/audio/.*")
# // list(FILTER SRC_FILES EXCLUDE REGEX "src/audioengine_config_override.cpp")

# Add replay editor audio sources - BEFORE config.cpp so override takes precedence
list(APPEND SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/workarounds/audioengine_config_override.cpp"
    "${CMAKE_SOURCE_DIR}/src/workarounds/audioengine_error_stubs.cpp"    
    "${CMAKE_SOURCE_DIR}/3rd-party/osuReplayEditorV3/ReplayEditor/audioengine.cpp"
    # // "${CMAKE_SOURCE_DIR}/3rd-party/osuReplayEditorV3/ReplayEditor/config.cpp"
)


# Create executable
add_executable(${PROJECT_NAME} ${SRC_FILES})


# Add src/ directory
target_include_directories(${PROJECT_NAME} PRIVATE 
    # "${CMAKE_SOURCE_DIR}/src/"
    "${CMAKE_SOURCE_DIR}/src/core"
    "${CMAKE_SOURCE_DIR}/src/debug"
    "${CMAKE_SOURCE_DIR}/src/data"
    "${CMAKE_SOURCE_DIR}/src/state"
    "${CMAKE_SOURCE_DIR}/src/state/managers"
    "${CMAKE_SOURCE_DIR}/src/rendering"
    "${CMAKE_SOURCE_DIR}/src/audio"
    "${CMAKE_SOURCE_DIR}/src/workarounds"

    "${CMAKE_SOURCE_DIR}/src/resources/skins"
    
)

# Add osu-parser native C++ library
target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}/3rd-party/osu-parser/include"
    "${CMAKE_SOURCE_DIR}/3rd-party/osu-parser/include/osu!parser/Parser"
)

# Add osuReplayEditorV3 dependencies
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/3rd-party/osuReplayEditorV3/ReplayEditor"
    "${CMAKE_SOURCE_DIR}/3rd-party/osuReplayEditorV3/ReplayEditor/thirdparty/bass24"
)

# SDL2
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

# SDL2_ttf
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(SDL2_TTF_PKG SDL2_ttf QUIET)
    if(SDL2_TTF_PKG_FOUND)
        target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_TTF_PKG_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_TTF_PKG_LIBRARIES})
    endif()
endif()

# OpenGL
find_package(OpenGL)
if(OpenGL_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
endif()

# Platform helpers
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl pthread)
endif()


# BASS & BASS_FX
target_link_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/3rd-party/osuReplayEditorV3/ReplayEditor/thirdparty/bass24"
)
target_link_libraries(${PROJECT_NAME} PRIVATE bass bass_fx)