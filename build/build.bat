@echo off
setlocal
call project.bat

set target=%binarydir%\%project%.exe
set cc=clang
set cflags=-m64 -std=c17
set includes=-I%includedir%
set links=-L. -L%binarydir% -lmingw32 -lBearLibTerminal
set sources=%sourcedir%\*.c

%cc% %cflags% -o%target% %includes% %sources% %links%

endlocal
