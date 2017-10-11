Remove-Item bin -Recurse -Force -ErrorAction Ignore
New-Item bin -type directory -Force
Copy-Item C:\mingw_dev_lib\bin\SDL2.dll .\bin\SDL2.dll
Copy-Item .\res .\bin -Recurse
mingw32-make.exe
