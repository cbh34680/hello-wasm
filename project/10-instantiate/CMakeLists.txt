cmake_minimum_required(VERSION 3.20)
project(10_instantiate LANGUAGES CXX)

add_executable(10_instantiate main.cpp)
target_link_options(10_instantiate PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
)
