cmake_minimum_required(VERSION 3.20)
project(12_monitor_dependencies LANGUAGES CXX)

add_executable(12_monitor_dependencies main.cpp)
target_link_options(12_monitor_dependencies PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORTED_RUNTIME_METHODS=addRunDependency,removeRunDependency,FS"
    "-sEXPORT_ES6=1"
)
