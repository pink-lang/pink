@echo off
setlocal

set PINK_HOME=%~dp0\src
set PINK_OS=win32

if exist bin\pink.exe (
  bin\pink.exe -nosourcemap -notypeinfo -o src\c\out_pink_win32.c src/pink
) else (
  echo.
  echo -- No pink binary found; using previously built src\c\out_pink_win32.c --
  echo.
)

gcc -Isrc\c\ -o dist\bin\pink.exe src\c\pink.c

endlocal
