@echo off
echo compile-windows.bat can auto compile all windows solutions.
echo ==========================================================
SETLOCAL

IF "%1"=="32" (set Machine=x86) else (set Machine=x64)
set ProjName=%2
set Config=%3
echo Machine: %Machine%
echo ProjName: %ProjName%
echo Config: %Config%

set Local_Path=%~dp0%
echo LocalPath: %Local_Path%
cd %Local_Path%
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" %Machine"%
msbuild %ProjName% /t:Rebuild /p:Configuration=%Config% /p:SubsystemVersion=5.1

