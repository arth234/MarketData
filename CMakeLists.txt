cmake_minimum_required(VERSION 3.10)

project(MarketData
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
include_directories(/usr/local/include)
add_executable(MarketData
  src/main.cpp
  src/Index.cpp
  src/ConstConcepts.cpp
  src/CandleServer.cpp
)

find_package(httplib REQUIRED)
target_link_libraries(MarketData httplib::httplib)

find_package(nlohmann_json REQUIRED)
target_link_libraries(MarketData nlohmann_json::nlohmann_json)

find_library(DUCKDB_LIB duckdb)
target_link_libraries(MarketData ${DUCKDB_LIB})

add_library(MarketDataLib STATIC
  src/Index.cpp
  src/ConstConcepts.cpp
  src/CandleServer.cpp
)

target_include_directories(MarketData PUBLIC include) 

install(TARGETS MarketData RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
install(TARGETS MarketData 
  LIBRARY DESTINATION lib 
  ARCHIVE DESTINATION lib)


