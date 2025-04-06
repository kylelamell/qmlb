cmake_minimum_required(VERSION 3.10)
project(QuantumMechanicsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(qmlb_src
  src/braket.cpp
  src/matrix.cpp
  src/complexNumber.cpp
)

add_library(qmlb STATIC ${qmlb_src})

target_include_directories(qmlb
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS qmlb
  EXPORT qmlb_config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(DIRECTORY include/
  DESTINATION include
)

install(EXPORT qmlb_config
  FILE qmlbConfig.cmake
  DESTINATION lib/cmake/qmlb
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(external/googletest)

enable_testing()
file(GLOB test_sources test/*.cpp)
foreach(test_source ${test_sources})
  get_filename_component(test_name ${test_source} NAME_WE)
  add_executable(${test_name} ${test_source})
  target_link_libraries(${test_name} qmlb gtest gtest_main)
  target_include_directories(${test_name}
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
      ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include
  )
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()