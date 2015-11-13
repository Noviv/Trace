# Trace [![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org) [![Forkability](https://img.shields.io/badge/forkability-high-green.svg)](https://basicallydan.github.io/forkability/?u=Noviv&r=Trace)
A Windows tool that allows users to diagnose their network devices and trace single packets. Latest Version: [v1.2.0](https://github.com/Noviv/Trace/releases/download/v1.2.0/Trace.exe)

## Download
Version | Quick Description | Download
--- | --- | ---
v1.2.0 | Much prettier output and more detailed information | [Download](https://github.com/Noviv/Trace/releases/download/v1.2.0/Trace.exe)
v1.1.0 | Prettier output | [Download](https://github.com/Noviv/Trace/releases/download/v1.1.0/Trace.exe)
v1.0.0 | Very simplistic inital version of Trace | [Download](https://github.com/Noviv/Trace/releases/download/v1.0.0/Trace.exe)

## Windows Development
You must have [CMake](https://cmake.org/) and [WinPcap](https://www.winpcap.org/) installed. This project was developed using WinPcap in Visual Studio 2015.
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../build</code> (or whatever you want it to be)</li>
  <li>Press "Generate" (<code>touch</code> and non-CMake files will not be deleted, but can be)</li>
  <li>Select the version of Visual Studio you want Trace to build into </li>
  <li>Move to <code>build/</code> and open the Visual Studio Solution file</li>
  <li>Right-click the Trace project in the Solution Explorer and set it as the startup project</li>
  <li>Right-click the Trace project in the Solution Explorer and open properties</li>
  <li>Move to <code>Linker --> Input</code> and add <code>wpcap.lib</code>, <code>ws2_32.lib</code>, and <code>Packet.lib</code></li>
  <li>Build solution/project (Ctrl+Shift+B or right click and press build)</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Delete files in <code>.../build</code>, press Configure, then Generate | Unsolved
Device Timeout | A device that is actually active may have the inactive label in the console | None (happens randomly) | N/A
Binary Data | Binary data is printed out as part of the payload | Future version will fix this | In progress

## To do
[&nbsp;&nbsp;] Clean up CMake file<br>
[&nbsp;&nbsp;] Find a better way to check whether or not a device is active<br>
[&nbsp;&nbsp;] Edit CONTRIBUTING and CHANGELOG<br>
