# Memory Analyzer

Memory Analyzer is a program helping out to analyze memory usage of a traceable
program.

## Requirements

* C++14 compiler
* CMake 3.5.1 (or newer)
* GTest

## Compiling

    mkdir bin
    cd bin
    cmake ..
    cd ..
    make -Cbin

## Running

The compiled binary is found at `bin/src/mem_anal`. You can run it as follows:

    $ bin/src/mem_anal <program>

You can find the unit test executables at `bin/src/test`.
