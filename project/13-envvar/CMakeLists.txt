cmake_minimum_required(VERSION 3.20)
project(13_envvar LANGUAGES CXX)

add_executable(13_envvar main.cpp)
target_link_options(13_envvar PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORTED_RUNTIME_METHODS=ENV"
    "-sEXPORT_ES6"
)
