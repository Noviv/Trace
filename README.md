# Trace [![Build Status](https://travis-ci.org/Noviv/Trace.svg)](https://travis-ci.org/Noviv/Trace)
A tool that allows a user to select and trace a single packet.

## Download
Version | Description | Download
--- | --- | ---
v1.0.0 | Windows only version that allows for the user to select an interface and monitor traffic. Packet-tracing not avaliable in this version. | [Download](https://github.com/Noviv/Trace/releases/download/v1.0.0/Trace.exe)

## Code
You must have [CMake](https://cmake.org/) and a Pcap library installed. The library used in this project is [WinPcap](https://www.winpcap.org/). Linux is also supported: use <code>sudo apt-get install libpcap-dev</code> to install Libpcap on a Linux machine.
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../build</code> (or whatever you want it to be)</li>
  <li>Press "Generate" (<code>touch</code> and non-CMake files will be deleted)</li>
  <li>Select the version of Visual Studio you want Trace to build into </li>
  <li>Move to <code>build/</code> and open the Visual Studio Solution file</li>
  <li>Right-click the Trace project in the Solution Explorer and set it as the startup project</li>
  <li>Right-click the Trace project in the Solution Explorer and open properties</li>
  <li><b>Windows only:</b> Move to <code>Linker --> Input</code> and add <code>wpcap.lib</code> and <code>ws2_32.lib</code>.
  <li>Build solution/project (Ctrl+Shift+B or right click and press build)</li>
  <li>Done!</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Delete files in <code>.../build</code>, press Configure, then Generate | Unsolved
Device Timeout | A device that is actually active may have the timeout label in the console | None, happens sporadically | Unsolved


## Branches
<code>master</code> - most recent updates<br>
<code>build</code> - stable build<br>

## To do
[&nbsp;&nbsp;] Add instructions for other CMake generators (i.e. Borland, Ninja, CodeBlocks)<br>
[&nbsp;&nbsp;] Clean up CMake file<br>
[&nbsp;&nbsp;] Write seperate instructions for Windows/Linux
