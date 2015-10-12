# Trace
A tool that allows a user to select and trace a single packet.

## Use
<ol>
  <li>Install CMake and a PCAP library ([WinPcap](https://www.winpcap.org/) works)</li>
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
