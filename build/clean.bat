@echo off
setlocal
call project.bat
del %binarydir%\%project%.exe
endlocal
