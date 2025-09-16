cmake_minimum_required(VERSION 3.10)
project(QuantumMechanicsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(qmlb_src
  src/state.cpp
  src/equation.cpp
  src/matrix.cpp
  src/complexNumber.cpp
)

add_library(qmlb STATIC ${qmlb_src})



