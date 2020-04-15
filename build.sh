#!/bin/bash
$ mkdir build
$ pushd build
$ cmake -G "Visual Studio 12 2013" ..\
$ cmake --build . --target INSTALL --config Release
$ popd

