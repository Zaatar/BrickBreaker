@echo off

::Create build directory
set buildDir=%~dp0..\build
if not exist %buildDir% mkdir %buildDir%
pushd %buildDir%

::Create object directory
set objDir=.\obj
if not exist %objDir% (
    mkdir %objDir%
    mkdir %objDir%\engine
    mkdir %objDir%\game
)

::Needed folder
set scriptDir=%~dp0..\scripts

::Use make to build default target
cd %scriptDir%\
mingw32-make

popd