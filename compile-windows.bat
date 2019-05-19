@echo off
echo compile-windows.bat can auto compile all windows solutions.
echo ==========================================================
SETLOCAL

IF "%1"=="32" (set Machine=x86) else (set Machine=x64)
IF "%4"=="2017" (set platformTool=2017) else (set platformTool=2013)
set ProjName=%2
set Config=%3
echo Machine: %Machine%
echo ProjName: %ProjName%
echo Config: %Config%
echo platformTool: %platformTool%

set Local_Path=%~dp0%
echo LocalPath: %Local_Path%
cd %Local_Path%

if %platformTool% == 2017 (
    if %Machine% == x64 (
        echo "vs2017-x64 compile ============================"
        call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" %Machine%
        msbuild %ProjName% /t:Rebuild /p:Configuration=%Config% /p:Platform=%Machine%
) else if %Machine% == x86 (
        echo "vs2017-x86 compile ============================"
        call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" %Machine%
        msbuild %ProjName% /t:Rebuild /p:Configuration=%Config% /p:Platform="Win32" /p:SubsystemVersion=5.1
)
) else (
    if %Machine% == x64 (
    echo "vs2013-x64 compile ============================"
    call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" %Machine"%
    msbuild %ProjName% /t:Rebuild /p:Configuration=%Config% /p:Platform=%Machine%
) else if %Machine% == x86 (
    echo "vs2013-x86 compile ============================"
    call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" %Machine"%
    msbuild %ProjName% /t:Rebuild /p:Configuration=%Config% /p:Platform="Win32" /p:SubsystemVersion=5.1
)
)



