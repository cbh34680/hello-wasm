cmake_minimum_required(VERSION 3.20)
project(06_dll_dynalib LANGUAGES CXX)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

add_executable(06_dll_dynalib_main func.cpp)
set_target_properties(06_dll_dynalib_main PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_options(06_dll_dynalib_main PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sMAIN_MODULE=2"
    "-sEXPORTED_FUNCTIONS=_malloc,_free,_vprintf"
    "-sEXPORTED_RUNTIME_METHODS=wasmExports,ccall,stringToUTF8OnStack,UTF8ToString,HEAP32"
    "-sERROR_ON_UNDEFINED_SYMBOLS=0"
    "--pre-js=${CMAKE_SOURCE_DIR}/pre.js"
)

add_library(06_dll_dynalib_side SHARED util.cpp)
set_target_properties(06_dll_dynalib_side PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_options(06_dll_dynalib_side PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sSIDE_MODULE=2"
)
set_target_properties(06_dll_dynalib_side PROPERTIES
    OUTPUT_NAME "06_dll_dynalib_side"
    PREFIX ""
    SUFFIX ".wasm" 
)
