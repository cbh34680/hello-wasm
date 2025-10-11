cmake_minimum_required(VERSION 3.20)
project(09_modularize_es6 LANGUAGES CXX)

add_executable(09_modularize_es6 main.cpp)
target_link_options(09_modularize_es6 PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
)

add_executable(09_modularize_es6_alias main.cpp)
target_link_options(09_modularize_es6_alias PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
)
