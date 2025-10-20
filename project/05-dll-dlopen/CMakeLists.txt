cmake_minimum_required(VERSION 3.20)
project(05_dll_dlopen LANGUAGES CXX)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

add_executable(05_dll_dlopen_main func.cpp)
set_target_properties(05_dll_dlopen_main PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_options(05_dll_dlopen_main PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sMAIN_MODULE=2"
    "-sEXPORTED_FUNCTIONS=_malloc,_free,_vprintf"
    "-sEXPORTED_RUNTIME_METHODS=wasmExports,ccall,stringToUTF8OnStack,UTF8ToString,HEAP32"
    #"-sERROR_ON_UNDEFINED_SYMBOLS=0"
)

add_library(05_dll_dlopen_side SHARED util.cpp)
set_target_properties(05_dll_dlopen_side PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_options(05_dll_dlopen_side PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sSIDE_MODULE=2"
)
set_target_properties(05_dll_dlopen_side PROPERTIES
    PREFIX ""
    SUFFIX ".wasm" 
)
