cmake_minimum_required(VERSION 3.20)
project(07_hook_module LANGUAGES CXX)

add_executable(07_hook_module main.cpp)
target_link_options(07_hook_module PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "--extern-pre-js=${CMAKE_SOURCE_DIR}/extern-pre.js"
    "--pre-js=${CMAKE_SOURCE_DIR}/pre.js"
)
