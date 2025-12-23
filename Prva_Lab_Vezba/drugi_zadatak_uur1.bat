
@echo off

set /p folder=Naziv foldera: 
set /p fajl=Naziv fajla: 

cd %folder%
dir > %fajl%
copy %fajl% ..\c\k\%fajl%

attib +r ..\c\k\%fajl%
cd ..\c\k
start notepad.exe %fajl%