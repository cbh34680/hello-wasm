cmake_minimum_required(VERSION 3.20)
project(14_nodejs LANGUAGES CXX)

add_executable(14_nodejs main.cpp)
target_link_options(14_nodejs PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6"
)
