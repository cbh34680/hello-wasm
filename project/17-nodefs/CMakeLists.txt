cmake_minimum_required(VERSION 3.20)
project(17_nodefs LANGUAGES CXX)

# 環境変数の EMSDK(C:\wasm\tool\emsdk-4.0.16) を変数(EMSDK) に設定
set(EMSDK $ENV{EMSDK})
message(STATUS "EMSDK is [${EMSDK}]")

add_executable(17_nodefs main.cpp)
target_link_options(17_nodefs PRIVATE
    $<$<CONFIG:Debug>:-gsource-map -sASSERTIONS=1 -sSAFE_HEAP=1>
    "-sEXPORT_ES6=1"
    "-sEXPORTED_RUNTIME_METHODS=FS,NODEFS"
    "--js-library=${EMSDK}/upstream/emscripten/src/lib/libnodefs.js"
)
