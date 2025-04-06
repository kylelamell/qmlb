cmake_minimum_required(VERSION 3.10)

project(QuantumMechanicsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(qmlb 
              main.cpp 
              braket.cpp braket.hpp
              matrix.cpp matrix.hpp
              complexNumber.cpp complexNumber.hpp)