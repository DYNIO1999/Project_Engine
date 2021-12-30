@ECHO OFF
SetLocal EnableDelayedExpansion


REM Get a list of all the .cpp files.
SET cppFilenames=
FOR /R %%f in (*.cpp) do (
    SET cppFilenames=!cppFilenames! %%f
)

REM output exe file
SET assembly=engine

REM flags, to show warnings etc
SET compilerFlags=-Wall

REM include headers from other libs and local ones. -I and path
SET includeFlags=-Isrc -I..\dependencies\SFML\include -I..\dependencies\ImGUI

REM include lib to the linker need to be careful about ordering.
SET linkerFlags=-L..\dependencies\SFML\lib -l sfml-graphics-s -l sfml-window-s -l sfml-audio-s -l sfml-system-s -l gdi32 -l winmm -l opengl32 -l freetype -l openal32 -l flac -l vorbisenc -l vorbisfile  -l vorbis -l ogg




ECHO "Building %assembly%..."
g++ %cppFilenames% -o %assembly% %compilerFlags% %includeFlags% %linkerFlags% 