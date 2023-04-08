@echo off
echo start reg  ...
set df=%~dp0ConsoleApplication4.exe
echo %df%
echo %dk%
reg add "HKCR\ceshi" /v "URL Protocol"  /d %~dp0ConsoleApplication4.exe /f
reg add "HKCR\ceshi\DefaultIcon"   /d %~dp0ConsoleApplication4.exe,1 /f
reg add "HKCR\ceshi\shell\open\command"  /d "\"%~dp0ConsoleApplication4.exe\" \"%%1\""  /f



pause
@echo on