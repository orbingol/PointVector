# Point and Vector Template Classes

This repository provides n-dimensional point and vector implementations in C++ programming language. The code is
compatible with C++11 standard.

## Building

### Library

`Point` and `Vector` classes are [template classes](https://isocpp.org/wiki/faq/templates).
Therefore, no pre-compilation steps are required. Directly copy files to your project, include them in your header files
and they should work.

### Demo applications

Please use [CMake](https://cmake.org) to build the demo applications `point` and `vector`. You may use the following commands:

`make; make install`

### Documentation

You need [doxygen](http://www.stack.nl/~dimitri/doxygen/) to build the documentation. A sample configuration file is provided under `docs/` directory.
You may use the following command to generate the documentation from the source files:

`doxygen docs/DoxyFile`

Alternatively, you may use `DoxyWizard` GUI to generate the documentation.

## Testing

This project uses [Catch Framework](https://github.com/catchorg/Catch2) for implementing unit tests. All tests can be found under `tests/` directory. 
You may execute the tests using the following command:

`make test`

Visual Studio users may build `RUN_TESTS` project to run the tests.

**Note:** This repository contains header files of Catch Framework v2.1.2 for convenience in building tests.

## Author

* Onur Rauf Bingol ([@orbingol](https://github.com/orbingol))

## License

* PointVector is licensed under the [MIT License](LICENSE)
* Catch Framework is licensed under the [Boost Software License v1.0](https://www.boost.org/LICENSE_1_0.txt)
