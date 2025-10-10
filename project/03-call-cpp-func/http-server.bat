@echo off

cd %~dp0
call ..\..\env.bat

start "Python HttpServer(8080)" python -m http.server 8080
