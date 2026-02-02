@echo off
REM Build script for Wildlife Sanctuary Simulator (Windows)
REM Requires MinGW or Visual Studio Developer Command Prompt

echo ============================================
echo Wildlife Sanctuary Simulator - Build Script
echo ============================================
echo.

REM Check if g++ is available
where g++ >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Found g++ compiler. Building with g++...
    echo.
    
    g++ -std=c++11 -Wall -Wextra -o zoo_simulator.exe ^
        main.cpp Animal.cpp Mammal.cpp Bird.cpp ^
        Lion.cpp Elephant.cpp Monkey.cpp ^
        Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp
    
    if %ERRORLEVEL% EQU 0 (
        echo.
        echo ============================================
        echo Build successful!
        echo Executable: zoo_simulator.exe
        echo ============================================
        echo.
        echo Run the program with: zoo_simulator.exe
        echo Or press any key to run now...
        pause >nul
        zoo_simulator.exe
    ) else (
        echo.
        echo ============================================
        echo Build failed! Check errors above.
        echo ============================================
        pause
    )
) else (
    echo ERROR: g++ compiler not found!
    echo.
    echo Please install one of the following:
    echo   - MinGW: https://sourceforge.net/projects/mingw/
    echo   - Visual Studio: Use Developer Command Prompt
    echo.
    echo Or compile manually:
    echo   g++ -std=c++11 -o zoo_simulator.exe main.cpp Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Monkey.cpp Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp
    echo.
    pause
)
