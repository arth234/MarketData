cmake_minimum_required(VERSION 3.10)
project(MarketData VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MarketData 
src/main.cpp
src/MarketData.cpp)

target_include_directories(MarketData PRIVATE
include lib)
