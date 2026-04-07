# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/duckdb-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${duckdb_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${duckdb_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET duckdb::duckdb)
    add_library(duckdb::duckdb INTERFACE IMPORTED)
    message(${duckdb_MESSAGE_MODE} "Conan: Target declared 'duckdb::duckdb'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/duckdb-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()