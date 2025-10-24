cmake_minimum_required(VERSION 3.20)
project(16_awk LANGUAGES C)

file(GLOB SOURCES "awk/*.c")
add_executable(16_awk ${SOURCES})

target_link_options(16_awk PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
    # https://github.com/geocommons/geocoder/blob/master/test/data/address-sample.csv
    "--preload-file=${CMAKE_SOURCE_DIR}/address-sample.csv@address-sample.csv"
)
