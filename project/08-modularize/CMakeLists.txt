cmake_minimum_required(VERSION 3.20)
project(08_modularize LANGUAGES CXX)

add_executable(08_modularize main.cpp)
target_link_options(08_modularize PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sMODULARIZE=1"
)

add_executable(08_modularize_alias main.cpp)
target_link_options(08_modularize_alias PRIVATE
    "-gsource-map"
    "-sASSERTIONS=1"
    "-sSAFE_HEAP=1"
    "-sMODULARIZE=1"
    "-sEXPORT_NAME=AliasModule"
)
