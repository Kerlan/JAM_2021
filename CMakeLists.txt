cmake_minimum_required(VERSION 3.5)
set(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)
set(CONAN_DISABLE_CHECK_COMPILER ON)

set(NAME_CLIENT 123boom)
set(INCLUDE_CLIENT "client/include")
project(${NAME_CLIENT} LANGUAGES CXX)

set(SRC_CLIENT
    
    )
    
set(HPP_CLIENT
    
    )

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(${NAME_CLIENT} ${SRC_CLIENT} ${HPP_CLIENT})

target_link_libraries(${NAME_CLIENT} PUBLIC CONAN_PKG::boost CONAN_PKG::sfml)

target_include_directories(${NAME_CLIENT} PUBLIC ${CONAN_INCLUDE_DIRS_BOOST} ${CONAN_INCLUDE_DIRS_SFML} ${INCLUDE_CLIENT})

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)