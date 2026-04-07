cmake_minimum_required(VERSION 3.10)

project(MarketData
    VERSION 1.0
    LANGUAGES CXX
)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -march=native -pipe")

find_program(CCACHE_PROGRAM ccache)

include_directories(include)

if(CCACHE_PROGRAM)
  message(STATUS "Found ccache :{CCACHE_PROGRAM}")
  set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -pipe")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -pipe")
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(httplib REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Threads REQUIRED)
find_package(duckdb REQUIRED)


add_library(MarketDatalib STATIC
  src/Index.cpp
  src/ConstConcepts.cpp
  src/CandleServer.cpp
)

target_include_directories(MarketDatalib
  PUBLIC Include
)

add_executable(MarketData 
  src/main.cpp
)

target_link_libraries(
  MarketData 
  PRIVATE httplib::httplib
  PRIVATE nlohmann_json::nlohmann_json
  PRIVATE ${DUCKDB_LIB}
  PRIVATE Threads::Threads
  PRIVATE duckdb::duckdb
  PRIVATE MarketDatalib)
  

install(TARGETS MarketData RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
install(TARGETS MarketData 
  LIBRARY DESTINATION lib 
  ARCHIVE DESTINATION lib)


