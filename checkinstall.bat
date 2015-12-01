@echo off
cls
set "a=1"
if "%PCAP_ROOT_DIR%"==""  (
	set "a=2"
	echo PCAP_ROOT_DIR is not defined! WinPCAP needs to be installed.
) else (
	if not exist "%PCAP_ROOT_DIR%\\Include\\pcap\\pcap.h" (
		set "a=2"
		echo WinPCAP did not install properly, reinstall.
	)
)

if "%a%"=="1" (
	echo WinPCAP installed properly.
) else (
	echo WinPCAP needs to be [re]installed.
	echo Would you like to install WinPCAP version 4.1.3 automatically? [y/n]
	set /p choice="?:"
	if "%choice%"=="y" (
		bitsadmin /transfer WinPCAPInstall /download /priority normal https://www.winpcap.org/install/bin/WinPcap_4_1_3.exe %TEMP%\\winpcap.exe
		%TEMP%/winpcap.exe
		del %TEMP%\\winpcap.exe
	)
)