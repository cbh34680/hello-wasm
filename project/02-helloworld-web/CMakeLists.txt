cmake_minimum_required(VERSION 3.20)
project(02_helloworld_web LANGUAGES CXX)

add_executable(02_helloworld_web main.cpp)
target_link_options(02_helloworld_web PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
)
