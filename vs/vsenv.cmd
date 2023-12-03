@echo off

where cl > nul 2> nul
if %ERRORLEVEL% equ 0 (
  exit /b
)

for /f "usebackq tokens=*" %%i in (`%~dp0\vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
  set InstallDir=%%i
)

if exist "%InstallDir%\Common7\Tools\vsdevcmd.bat" (
  pushd .
  call "%InstallDir%\Common7\Tools\vsdevcmd.bat" %*
  popd
)