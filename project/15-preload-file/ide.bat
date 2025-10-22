@echo off

cd %~dp0
call ..\..\env.bat

code . > nul
