cpp-algorithms
------------

![cpp-algorithms build status](https://api.travis-ci.org/SRombauts/cpp-algorithms.png "cpp-algorithms build status")

Experimenting with well known algorithms and data structures.

Copyright (c) 2013-2021 Sébastien Rombauts (sebastien.rombauts@gmail.com)

## Building & testing with CMake

### Get Google Test submodule

```bash
git submodule init
git submodule update
```

### Typical generic build (see also "build.bat" or "./build.sh")

```bash
mkdir build
cd build
cmake ..        # cmake .. -G "Visual Studio 10"    # for Visual Studio 2010
cmake --build . # make
ctest .         # make test
```

### Debug build for Unix Makefiles

```bash
mkdir Debug
cd Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug   # -G "Unix Makefiles"
cmake --build . # make
ctest .         # make test
```

### Release build

```bash
mkdir Release
cd Release
cmake .. -DCMAKE_BUILD_TYPE=Release  # -G "Unix Makefiles"
cmake --build . # make
ctest .         # make test
```

### Continuous Integration

This project is continuously tested under Ubuntu Linux with the gcc and clang compilers
using the Travis CI community service with the above CMake building and testing procedure.

Detailed results can be seen online: https://travis-ci.org/SRombauts/cpp-algorithms

