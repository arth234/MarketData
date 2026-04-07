########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(duckdb_FIND_QUIETLY)
    set(duckdb_MESSAGE_MODE VERBOSE)
else()
    set(duckdb_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/duckdbTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${duckdb_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(duckdb_VERSION_STRING "0.8.1")
set(duckdb_INCLUDE_DIRS ${duckdb_INCLUDE_DIRS_RELEASE} )
set(duckdb_INCLUDE_DIR ${duckdb_INCLUDE_DIRS_RELEASE} )
set(duckdb_LIBRARIES ${duckdb_LIBRARIES_RELEASE} )
set(duckdb_DEFINITIONS ${duckdb_DEFINITIONS_RELEASE} )


# Definition of extra CMake variables from cmake_extra_variables


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${duckdb_BUILD_MODULES_PATHS_RELEASE} )
    message(${duckdb_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


