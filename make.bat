@echo off
setlocal

set PINK_HOME=%~dp0\dist
set PINK_OS=windows
  
dist\bin\pink.exe -nosourcemap -o src\c\out_pink.c src/pink

md dist\bin

cl /MP /FS /Ox /W0 /nologo src\c\pink.c /Fe:dist\bin\pink.exe /EHsc /link /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:LIBCMT  kernel32.lib vcruntime.lib msvcrt.lib 

endlocal
