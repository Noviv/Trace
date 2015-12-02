# Trace [![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org) [![Forkability](https://img.shields.io/badge/forkability-high-green.svg)](https://basicallydan.github.io/forkability/?u=Noviv&r=Trace)
A Windows tool that allows users to diagnose their network devices and trace single packets. Latest Version: [v1.3.0](https://github.com/Noviv/Trace/releases/download/v1.3.0/Trace.exe)

## Download
Version | Quick Description | Download | Changelog
--- | --- | --- | ---
v1.3.0 | Fullscreen output and performance optimization | [Download](https://github.com/Noviv/Trace/releases/download/v1.3.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v130)
v1.2.0 | Much prettier output and more detailed information | [Download](https://github.com/Noviv/Trace/releases/download/v1.2.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v120)
v1.1.0 | Prettier output | [Download](https://github.com/Noviv/Trace/releases/download/v1.1.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v110)
v1.0.0 | Very simplistic inital version of Trace | [Download](https://github.com/Noviv/Trace/releases/download/v1.0.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v100)

## Windows Development
You must have [CMake](https://cmake.org/) and [WinPcap](https://www.winpcap.org/) installed. This project was developed using WinPcap in Visual Studio 2015.
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../build</code> (or whatever you want it to be)</li>
  <li>Press "Generate" (<code>touch</code> will not be deleted, but can be because it is not used in this project)</li>
  <li>Select the version of Visual Studio you want Trace to build into </li>
  <li>Move to <code>build/</code> and open the Visual Studio Solution file</li>
  <li>Right-click the Trace project in the Solution Explorer and set it as the startup project</li>
  <li>Build solution/project (Ctrl+Shift+B or right click and press build)</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Fixed in v1.3.0 | Fixed
Device Timeout | A device that is actually active may have the inactive label in the console | None (happens randomly) | N/A
Beep | Cmd creates a beep when binary data is printed | Type <code>net stop beep</code> into admin command prompt (<code>net start beep</code> to bring it back) | ["Fixed"](http://stackoverflow.com/a/7977903)

## To do
[&nbsp;&nbsp;] Clean up CMake file<br>
[&nbsp;&nbsp;] Find a better way to check whether or not a device is active<br>
[&nbsp;&nbsp;] Edit CONTRIBUTING and CHANGELOG<br>
