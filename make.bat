@echo off
setlocal

set PINK_HOME=%~dp0\dist
set PINK_OS=windows

call vs\vsenv -arch=x64
  
dist\bin\pink.exe -nosourcemap -o src\c\out_pink.c src/pink

md dist\bin

gcc src\c\pink.c -o dist\bin\pink.exe

endlocal
