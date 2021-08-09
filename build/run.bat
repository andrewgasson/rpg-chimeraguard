@echo off
setlocal
call project.bat
call %binarydir%\%project%.exe
endlocal
