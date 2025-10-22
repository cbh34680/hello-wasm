cmake_minimum_required(VERSION 3.20)
project(15_preload_file LANGUAGES CXX)

add_executable(15_preload_file main.cpp)

target_link_options(15_preload_file PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORTED_RUNTIME_METHODS=FS"
    "-sEXPORT_ES6=1"
    "--preload-file=${CMAKE_SOURCE_DIR}/data.txt@data.txt"
    #"--embed-file=${CMAKE_SOURCE_DIR}/data.txt@data.txt"
)
