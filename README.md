[![Build Status](https://travis-ci.org/bast/gtest-demo.svg?branch=master)](https://travis-ci.org/bast/gtest-demo/builds)
[![Coverage Status](https://coveralls.io/repos/bast/gtest-demo/badge.png?branch=master)](https://coveralls.io/r/bast/gtest-demo?branch=master)
[![License](https://img.shields.io/github/license/evster-coder/IndustrialRobotSystemConsoleFixed)]


# IndustrialRobotSystem Console Fixed version

It includes the source code of system for imitation Industrial Robot Manage framework (c++)

## How to build this demo

```bash
git clone https://github.com/bast/gtest-demo.git
cd gtest-demo
mkdir build
cd build
cmake ..
cmake --build .
```


## Running the tests

Either using `ctest`:
```
$ ctest

Running tests...
Test project /home/user/gtest-demo/build
    Start 1: unit
1/1 Test #1: unit .............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```

Or directly using `unit_tests`:
```
$ ./bin/unit_tests

```
