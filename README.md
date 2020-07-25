geos-cli
========

A Command line interface for [GEOS - Geometry Engine Open Source](https://github.com/libgeos/geos).

Each command does one thing well (buffer, centroid, envelope) by reading in a geometry, processing the geometry, and writing the geometry out as WKT. Individual commands can be connected with unix pipes.

```bash
geos-cli buffer -g "POINT (1 1)" -d 10 | geos-cli centroid
```

geos-cli is written in C++ using [CLI11](https://github.com/CLIUtils/CLI11) and [GEOS](https://github.com/libgeos/geos).  The [Google Test](https://github.com/google/googletest) library is used to write unit tests.  The project is built with [CMake](https://cmake.org/) and dependencies are managed with [conan](https://conan.io/).

Build
-----

```bash
mkdir build
cd build
conan install ..
conan -g "Unix Makefiles" .
conant --build .
```