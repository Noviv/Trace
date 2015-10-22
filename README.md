# Trace [![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org) [![Forkability](https://img.shields.io/badge/forkability-limited-yellow.svg)](https://basicallydan.github.io/forkability/?u=Noviv&r=Trace)
A Windows only tool that allows a user to select and trace a single packet. Latest Version: [v1.1.0](https://github.com/Noviv/Trace/releases/download/v1.1.0/Trace.exe)

## Download
Version | Description | Download
--- | --- | ---
v1.1.0 | Wndows only version that gives information about all network devices and allows the user to select and interface to monitor. Packet-tracing still not avaliable. | [Download](https://github.com/Noviv/Trace/releases/download/v1.1.0/Trace.exe)
v1.0.0 | Windows only version that allows for the user to select an interface and monitor traffic. Packet-tracing not avaliable in this version. | [Download](https://github.com/Noviv/Trace/releases/download/v1.0.0/Trace.exe)

## Windows Build
You must have [CMake](https://cmake.org/) and [WinPcap](https://www.winpcap.org/) installed. This project was developed using WinPcap in Visual Studio 2015.
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../build</code> (or whatever you want it to be)</li>
  <li>Press "Generate" (<code>touch</code> and non-CMake files will be deleted)</li>
  <li>Select the version of Visual Studio you want Trace to build into </li>
  <li>Move to <code>build/</code> and open the Visual Studio Solution file</li>
  <li>Right-click the Trace project in the Solution Explorer and set it as the startup project</li>
  <li>Right-click the Trace project in the Solution Explorer and open properties</li>
  <li>Move to <code>Linker --> Input</code> and add <code>wpcap.lib</code> and <code>ws2_32.lib</code></li>
  <li>Build solution/project (Ctrl+Shift+B or right click and press build)</li>
  <li>Done!</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Delete files in <code>.../build</code>, press Configure, then Generate | Unsolved
Device Timeout | A device that is actually active may have the timeout label in the console | None, happens sporadically | Unsolved

## To do
[&nbsp;&nbsp;] Clean up CMake file<br>
