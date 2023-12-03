@echo off
setlocal

set PINK_HOME=%~dp0\src
set PINK_OS=win32

call vs\vsenv -arch=x64

if exist bin\pink.exe (
  bin\pink.exe -nosourcemap -notypeinfo -o src\c\out_pink_win32.c src/pink
) else (
  echo.
  echo -- No pink binary found; using previously built src\c\out_pink_win32.c --
  echo.
)

md dist\bin

cl /Fe:dist\bin\pink /Fo:dist\bin\pink src\c\pink.c

endlocal
