# Contributing
If you are interested in contributing something to Trace, this document will give you all the tools necessary.

### Setting Up the Build Environment

Software | Tested Version | Required
--- | --- | ---
[Visual Studio](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx) | VS Community 2015 v14.0.23107.0 | yes (any version)
[WinPCAP](https://www.winpcap.org/install/default.htm) | v4.1.0.2980 | yes (v4.0+)
[WinPCAP Dev](https://www.winpcap.org/devel.htm) | v4.1.2 | yes (v4.0+)
[CMake](https://cmake.org/) | v3.4.0-rc1 (cmake-gui) | yes (v2.8+)
[Inno Setup Compiler](http://www.jrsoftware.org/isinfo.php) | v5.5.6 (a) | no


<ol>
	<li>Listed above is the tested dev environment for Trace. Install the required software.</li>
	<li>Make a new environment variable <code>PCAP_ROOT_DIR</code> and set it to the folder that contains Pcap.</li>
	<li>Open CMake GUI.</li>
	<li>Set source directory to <code>.../src</code> and the build directory to <code>.../build</code>.</li>
	<li>Press "Generate" (<code>touch</code> will not be deleted, but can be because it is not used in this project).</li>
	<li>Select the version of Visual Studio you want Trace to build into.</li>
	<li>Move to <code>build/</code> and open the Visual Studio Solution file.</li>
	<li>Right-click the Trace project in the Solution Explorer and set it as the startup project.</li>
	<li>Build solution/project (Ctrl+Shift+B or right click and press build).</li>
	<li>(optional) Open <code>Trace_package.iss</code> and build the script in order to create the installer package.</li>
	<li>After building from Visual Studio, run Trace.exe. If there are no problems, the build environment has been set up successfully.</li>
</ol>

### Project Structure
All folders beginning with <code>_</code> are used in the creation of the installation package.
- <code>_package/</code> - contains all the files used in the Inno Setup script (license, information, etc)
	- <code>license.txt</code> - MIT license for Trace
    - <code>postinstall.txt</code> - information for user  (shown after installation) about use/uninstalling
- <code>_scripts/</code> - script files that are or will be used in Trace setup/installation
	- <code>Trace_package.iss</code> - Inno Setup script for installation package
    - <code>winpcap.bat</code> - automatically detect and if necessary install WinPCAP drivers/DLLs
	- <code>winpcapdev.bat</code> - automatically detect and if necessary download WinPCAP headers/libraries
- <code>build</code> - the directory in which CMake can build the Visual Studio files necessary to build Trace
- <code>src</code> - source files for Trace
	- <code>include/</code> - Trace header files
		- <code>a_devdiag.h</code> - active diagnostics header
		- <code>netstructures.h</code> - input network data structures
		- <code>a_devdiag.h</code> - passive diagnostics header
		- <code>tracepacket.h</code> - Trace data packet data structures
	- <code>src/</code> - Trace source files
    	- <code>a_devdiag.cpp</code> - active diagnostics source code
    	- <code>main.cpp</code> - Trace entry point
    	- <code>p_devdiag.cpp</code> - passive diagnostics source code
	- <code>CMakeLists.txt</code> - the CMake script for creating the build environment

<br><br>If you encounter any problems feel free to <a href="mailto:mwebbmwebb@gmail.com">email me</a>!
