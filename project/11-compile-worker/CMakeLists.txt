cmake_minimum_required(VERSION 3.20)
project(11_compile_worker LANGUAGES CXX)

add_executable(11_compile_worker main.cpp)
target_link_options(11_compile_worker PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
)
