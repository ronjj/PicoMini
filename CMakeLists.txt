cmake_minimum_required(VERSION 3.24)
project(picomini)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(CIMG_VERSION 3.4.1)
FetchContent_Declare(
    CImg
    URL https://github.com/GreycLab/CImg/archive/refs/heads/master.tar.gz
)

FetchContent_MakeAvailable(CImg)

set(SOURCE_FILES main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/opt/homebrew/include")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${cimg_SOURCE_DIR})

# Set JPEG library path for ARM-based Macs
set(JPEG_INCLUDE_DIR "/opt/homebrew/include")
set(JPEG_LIBRARY "/opt/homebrew/lib/libjpeg.dylib")

# Find and link against JPEG library
find_package(JPEG REQUIRED)
if(JPEG_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${JPEG_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${JPEG_LIBRARY})
else()
    message(FATAL_ERROR "JPEG library not found")
endif()

# macOS-specific settings
if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE cimg_display=0 cimg_use_jpeg cimg_use_cpp20)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework AppKit")
endif()
