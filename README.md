# Trace [![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org) [![Forkability](https://img.shields.io/badge/forkability-high-green.svg)](https://basicallydan.github.io/forkability/?u=Noviv&r=Trace)
A Windows tool that allows users to diagnose their network devices and trace single packets. Latest Version: [v1.3.0](https://github.com/Noviv/Trace/releases/download/v1.3.0/Trace.exe)

## Download
Version | Quick Description | Download | Changelog
--- | --- | --- | ---
v1.3.0 | Fullscreen output and performance optimization | [Download](https://github.com/Noviv/Trace/releases/download/v1.3.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v130)
v1.2.0 | Much prettier output and more detailed information | [Download](https://github.com/Noviv/Trace/releases/download/v1.2.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v120)
v1.1.0 | Prettier output | [Download](https://github.com/Noviv/Trace/releases/download/v1.1.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v110)
v1.0.0 | Very simplistic inital version of Trace | [Download](https://github.com/Noviv/Trace/releases/download/v1.0.0/Trace.exe) | [Changelog](https://github.com/Noviv/Trace/blob/master/CHANGELOG.md#v100)

## Known Bugs
Name | Description | Workaround | Status
--- | --- | --- | ---
Beep | Cmd creates a beep when binary data is printed | Type <code>net stop beep</code> into admin command prompt (<code>net start beep</code> to bring it back) | ["Fixed"](http://stackoverflow.com/a/7977903)
