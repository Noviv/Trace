@echo off
cls
set "a=1"
if "%PCAP_ROOT_DIR%"==""  (
	echo PCAP_ROOT_DIR is not defined! Please set this environment variable.
) else (
	if not exist "%PCAP_ROOT_DIR%\\Include\\pcap\\pcap.h" (
		set "a=2"
		echo WinPCAP Dev did not install properly, reinstall.
	)
)

if "%a%"=="1" (
	echo WinPCAP Dev installed properly.
) else (
	echo WinPCAP Dev needs to be [re]installed.
	echo Would you like to install WinPCAP Dev version 4.1.3 automatically? [y/n]
	set /p choice="?:"
	if "%choice%"=="y" (
		bitsadmin /transfer WinPCAPInstall /download /priority normal https://www.winpcap.org/install/bin/WpdPack_4_1_2.zip .\\winpcapdev.zip
	)
)

echo Finished!

pause
exit