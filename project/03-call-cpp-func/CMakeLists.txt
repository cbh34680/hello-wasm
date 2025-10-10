cmake_minimum_required(VERSION 3.20)
project(03_call_cpp_func LANGUAGES CXX)

add_executable(03_call_cpp_func func.cpp)
target_link_options(03_call_cpp_func PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "--no-entry"
    "-sEXPORTED_FUNCTIONS=_malloc,_free"
    "-sEXPORTED_RUNTIME_METHODS=wasmExports,ccall,stringToUTF8OnStack,UTF8ToString,HEAP32"
)

