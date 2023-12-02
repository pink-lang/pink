@echo off
setlocal

md dist\bin
md dist\pinklib
xcopy /s .\src\pinklib .\dist\pinklib

endlocal