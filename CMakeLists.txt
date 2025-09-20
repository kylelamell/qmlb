cmake_minimum_required(VERSION 3.10)
project(QuantumMechanicsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(qmlb_src
  src/complexNumber.cpp
  src/matrix.cpp
  src/state.cpp
)

add_library(qmlb STATIC ${qmlb_src})

enable_testing()

add_executable(t_matrix test/test_matrix.cpp)
target_link_libraries(t_matrix qmlb)
add_test(NAME run_matrix COMMAND t_matrix)

add_executable(t_complexNumber test/test_complexNumber.cpp)
target_link_libraries(t_complexNumber qmlb)
add_test(NAME run_complexNumber COMMAND t_complexNumber)

add_executable(t_state test/test_state.cpp)
target_link_libraries(t_state qmlb)
add_test(NAME run_state COMMAND t_state)