# Trace [![Build Status](https://travis-ci.org/Noviv/Trace.svg)](https://travis-ci.org/Noviv/Trace)
A tool that allows a user to select and trace a single packet.

## Use
You must have [CMake](https://cmake.org/) and a Pcap library installed. The library used in this project is [WinPcap](https://www.winpcap.org/). Linux is not yet supported, but <code>sudo apt-get install libpcap-dev</code> can be used to install Libpcap on a Linux machine.
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../build</code> (or whatever you want it to be)</li>
  <li>Press "Generate" (<code>touch</code> and non-CMake files will be deleted)</li>
  <li>Select the version of Visual Studio you want Trace to build into </li>
  <li>Move to <code>build/</code> and open the Visual Studio Solution file</li>
  <li>Right-click the Trace project in the Solution Explorer and set it as the startup project</li>
  <li>Right-click the Trace project in the Solution Explorer and open properties</li>
  <li>Move to <code>Linker --> Input</code> and add <code>wpcap.lib</code> and <code>ws2_32.lib</code>.
  <li>Build solution/project (Ctrl+Shift+B or right click and press build)</li>
  <li>Done!</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Delete files in <code>build</code>, press Configure, then Generate | Unsolved
Linux | Linux CMake generation unsupported | Don't use Linux :( | Making a new CMake file


## Branches
<code>master</code> - most recent updates<br>
<code>build</code> - stable build<br>

## To do
[&nbsp;&nbsp;] Add instructions for other CMake generators (i.e. Borland, Ninja, CodeBlocks)<br>
[&nbsp;&nbsp;] Add CMake support for Linux and <code>Libpcap</code> header files
