# Trace
A tool that allows a user to select and trace a single packet.

## Use
You must have CMake and a Pcap library installed. The library used in this project is [WinPcap](https://www.winpcap.org/).
<ol>
  <li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap</li>
  <li>Open CMake GUI</li>
  <li>Set source directory to <code>.../cmake</code> and the build directory to <code>.../vs</code> (or whatever you want it to be)</li>
  <li>Press "Generate"</li>
  <li>Select the version of Visual Studio you want Trace to build into</li>
  <li>Move to <code>vs/</code> and open the Visual Studio Soltuion file</li>
</ol>

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Escape Character | Error about "\P" escape character shows up in CMake console | Delete generated files and regenerate | Unsolved
