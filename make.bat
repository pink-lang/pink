@echo off
setlocal

set PINK_HOME=%~dp0\src
set PINK_OS=win32

call vs\vsenv -arch=x64
  
dist\bin\pink.exe -nosourcemap -o src\c\out_pink_win32.c src/pink

md dist\bin

cl /Fe:dist\bin\pink /Fo:dist\bin\pink src\c\pink.c

endlocal
