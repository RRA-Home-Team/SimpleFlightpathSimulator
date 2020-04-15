@mkdir build
@pushd build
cmake -G "Visual Studio 16 2019" ..\
cmake --build . --target INSTALL --config Debug
@popd
