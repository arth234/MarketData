########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(duckdb_COMPONENT_NAMES "")
if(DEFINED duckdb_FIND_DEPENDENCY_NAMES)
  list(APPEND duckdb_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES duckdb_FIND_DEPENDENCY_NAMES)
else()
  set(duckdb_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(duckdb_PACKAGE_FOLDER_RELEASE "/home/arthur/.conan2/p/duckd3656f026e9de5/p")
set(duckdb_BUILD_MODULES_PATHS_RELEASE )


set(duckdb_INCLUDE_DIRS_RELEASE "${duckdb_PACKAGE_FOLDER_RELEASE}/include")
set(duckdb_RES_DIRS_RELEASE )
set(duckdb_DEFINITIONS_RELEASE )
set(duckdb_SHARED_LINK_FLAGS_RELEASE )
set(duckdb_EXE_LINK_FLAGS_RELEASE )
set(duckdb_OBJECTS_RELEASE )
set(duckdb_COMPILE_DEFINITIONS_RELEASE )
set(duckdb_COMPILE_OPTIONS_C_RELEASE )
set(duckdb_COMPILE_OPTIONS_CXX_RELEASE )
set(duckdb_LIB_DIRS_RELEASE "${duckdb_PACKAGE_FOLDER_RELEASE}/lib")
set(duckdb_BIN_DIRS_RELEASE )
set(duckdb_LIBRARY_TYPE_RELEASE STATIC)
set(duckdb_IS_HOST_WINDOWS_RELEASE 0)
set(duckdb_LIBS_RELEASE duckdb_static duckdb_fmt duckdb_pg_query duckdb_re2 duckdb_miniz duckdb_utf8proc duckdb_hyperloglog duckdb_fastpforlib duckdb_mbedtls duckdb_fsst jemalloc_extension)
set(duckdb_SYSTEM_LIBS_RELEASE pthread dl m)
set(duckdb_FRAMEWORK_DIRS_RELEASE )
set(duckdb_FRAMEWORKS_RELEASE )
set(duckdb_BUILD_DIRS_RELEASE )
set(duckdb_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(duckdb_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${duckdb_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${duckdb_COMPILE_OPTIONS_C_RELEASE}>")
set(duckdb_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${duckdb_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${duckdb_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${duckdb_EXE_LINK_FLAGS_RELEASE}>")


set(duckdb_COMPONENTS_RELEASE )