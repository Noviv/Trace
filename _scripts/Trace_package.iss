#define MyAppName "Trace"
#define MyAppVersion "1.4.0"
#define MyAppPublisher "Matthew Webb"
#define MyAppURL "github.com/Noviv/Trace"
#define MyAppExeName "Trace.exe"

[Setup]
AppId={{300BD7A7-8FC6-46E5-A81E-D1B4C233A6E8}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=..\\_package\\license.txt
InfoBeforeFile=..\_package\\preinstall.txt
InfoAfterFile=..\\_package\\postinstall.txt
OutputBaseFilename={#MyAppName + " v" + MyAppVersion + " Installer"}
Compression=lzma
SolidCompression=yes

[Code]
procedure InstallWinPCAP();
var
  ResultCode: Integer;
begin
  Exec(ExpandConstant('{app}\\WinPcap_4_1_3.exe'), '', '', SW_SHOWNORMAL,
    ewWaitUntilTerminated, ResultCode)
end;

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\_package\WinPcap_4_1_3.exe"; DestDir: "{app}"; AfterInstall: InstallWinPCAP
Source: "..\build\Debug\Trace.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

