cmake_minimum_required(VERSION 3.10)

project(MarketData
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
add_executable(MarketData
  src/main.cpp
  src/Index.cpp
  src/ConstConcepts.cpp
  src/CandleServer.cpp
)

if (MSVC)
  target_compile_options(MarketData PRIVATE /W4)
else()
  target_compile_options(MarketData PRIVATE -Wall -Wextra -Wpedantic)
endif()
