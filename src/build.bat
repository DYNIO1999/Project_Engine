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
SET includeFlags=-Isrc -I..\dependencies\GLFW\include -I..\dependencies\GLAD\include
REM include lib to the linker need to be careful about ordering.
SET linkerFlags=-L..\dependencies\GLFW\lib -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32


ECHO "Building %assembly%..."
g++ %cppFilenames% glad.c -o %assembly% %compilerFlags% %includeFlags% %linkerFlags%
