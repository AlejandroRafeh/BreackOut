@ECHO OFF

del *.obj *.pdb *.ilk *.exe

REM Compile application
cl /nologo /Zi /GR- /EHs /MDd -I ./include -I ./deps/esat/include ./main.cc .\deps\esat\bin\ESAT_d.lib opengl32.lib shell32.lib user32.lib gdi32.lib

