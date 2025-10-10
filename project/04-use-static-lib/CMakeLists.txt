cmake_minimum_required(VERSION 3.20)
project(04_use_static_lib LANGUAGES CXX)

add_executable(04_use_static_lib func.cpp)
target_link_options(04_use_static_lib PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "--no-entry"
    "-sEXPORTED_FUNCTIONS=_malloc,_free"
    "-sEXPORTED_RUNTIME_METHODS=wasmExports,ccall,stringToUTF8OnStack,UTF8ToString,HEAP32"
)

add_library(04_use_static_lib_util STATIC util.cpp)
target_link_libraries(04_use_static_lib PRIVATE 04_use_static_lib_util)
