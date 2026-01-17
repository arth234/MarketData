cmake_minimum_required(VERSION 3.10)
project(MarketData)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(MarketData
  src/main.cpp
  src/INDEX.cpp  
  src/MarketData.cpp
  src/ConstConcepts.cpp
)

target_include_directories(MarketData PRIVATE
  include
)

target_link_libraries(MarketData PRIVATE
  CURL::libcurl
)
