cmake_minimum_required(VERSION 3.10)

project(MarketData
    VERSION 1.0
    LANGUAGES CXX
)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Lib CURL
find_package(CURL REQUIRED)

add_executable(MarketData
    src/main.cpp
    src/INDEX.cpp
    src/MarketData.cpp
    src/ConstConcepts.cpp

)

target_include_directories(MarketData
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/json/include
)

target_link_libraries(MarketData
    PRIVATE
        CURL::libcurl
)

# Opcional: warnings decentes
if (MSVC)
    target_compile_options(MarketData PRIVATE /W4)
else()
    target_compile_options(MarketData PRIVATE -Wall -Wextra -Wpedantic)
endif()
