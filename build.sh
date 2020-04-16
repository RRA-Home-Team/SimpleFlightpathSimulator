#! /bin/bash
# This is the build script for Mac/Linux 
mkdir build
pushd build
cmake -G "Xcode" ..\
cmake --build . --target INSTALL --config Release
popd

