
@echo off

set /p folder=Naziv foldera: 
set /p fajl=Naziv fajla: 

cd /d %folder%
dir > %fajl%

copy %fajl% ..\c\k\%fajl%
attrib +r ..\c\k\%fajl%

cd /d ..\c\k
start notepad.exe %fajl%