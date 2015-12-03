@echo off
cls
echo Would you like to install WinPCAP version 4.1.3 automatically? [y/n]
set /p choice="?:"
if "%choice%"=="y" (
	bitsadmin /transfer WinPCAPInstall /download /priority normal https://www.winpcap.org/install/bin/WinPcap_4_1_3.exe %TEMP%\\winpcap.exe
	%TEMP%/winpcap.exe
	del %TEMP%\\winpcap.exe
)

echo Finished!

pause
exit