@echo off

@rem set PATH=C:\wasm\tool\python-3.14.0-embed-amd64;%PATH%
set PATH=C:\wasm\tool\clang+llvm-21.1.0-x86_64-pc-windows-msvc\bin;%PATH%
set PATH=C:\wasm\tool\cmake-4.1.2-windows-x86_64\bin;%PATH%
set PATH=C:\wasm\tool\emsdk-4.0.16;%PATH%
set PATH=C:\wasm\tool\ninja-win;%PATH%
set PATH=C:\wasm\tool\wabt-1.0.37-windows\wabt-1.0.37\bin;%PATH%
set PATH=C:\wasm\tool\wasmtime-v37.0.2-x86_64-windows;%PATH%

call C:\wasm\tool\emsdk-4.0.16\emsdk_env.bat

set PATH=%EMSDK%\python\3.13.3_64bit;%PATH%
set PATH=%EMSDK%\node\22.16.0_64bit\bin;%PATH%

if exist %~dp0add-env.bat call %~dp0add-env.bat

