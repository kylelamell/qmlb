cmake_minimum_required(VERSION 3.10)
project(QuantumMechanicsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(qmlb
  src/braket.cpp
  src.complexNUmber.cpp
  src/equation.cpp
  src/matrix.cpp
  src/state.cpp
)

add_library(qmlb STATIC ${qmlb_src})

add_executable(test_runner_matrix)
target_link_libraries(test_runner_matrix qmlb)
add_test(NAME run_tests COMMANS test_runner_matrix)

add_executable(test_runner_complex_numbers)
target_link_libraries(test_runner_complex_numbers qmlb)
add_test(NAME run_tests COMMANS test_runner_complex_numbers)

add_executable(test_runner_state)
target_link_libraries(test_runner_state qmlb)
add_test(NAME run_tests COMMANS test_runner_state)