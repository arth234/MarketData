cmake_minimum_required(VERSION 3.10)

project(MarketData
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.71 REQUIRED COMPONENTS system)
find_package(nlohmann_json REQUIRED)  # <--- adiciona isso
find_package(Crow REQUIRED)

add_executable(MarketData
    src/main.cpp
    src/Index.cpp
    src/ConstConcepts.cpp
    src/CandleServer.cpp
)

target_include_directories(MarketData
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# Linka bibliotecas
target_link_libraries(MarketData
    PRIVATE
        pthread
        ${Boost_LIBRARIES}
 
        nlohmann_json::nlohmann_json  # <--- linka o json
)
target_link_libraries(MarketData
  PRIVATE
  Crow::Crow
)

# Warnings
if (MSVC)
    target_compile_options(MarketData PRIVATE /W4)
else()
    target_compile_options(MarketData PRIVATE -Wall -Wextra -Wpedantic)
endif()
