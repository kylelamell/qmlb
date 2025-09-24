#include "matrix.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

struct test_case {
  bool (*test_ptr)();
  std::string test_name;
};

// TODO: bool ==
bool equals() {
  return true;
}

// TODO: bool !=
bool not_equals() {
  return true;
}

bool add_normal() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix M2({{CNum(4,4), CNum(3,3)},{CNum(2,2), CNum(1,1)}});
  Matrix Expected({{CNum(5,5), CNum(5,5)},{CNum(5,5), CNum(5,5)}});

  return (M1 + M2) == Expected;
}

bool add_wrong_dimension() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix M2({{CNum(1,1)},{CNum(2,2)}});

  try {
    Matrix M3 = M1 + M2;
    return false;
  }
  catch (const std::runtime_error& e) {
    return true;
  }
}

bool sub_normal() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix M2({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix Expected({{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}});

  return (M1 - M2) == Expected;
}

bool sub_wrong_dimension() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix M2({{CNum(1,1)},{CNum(2,2)}});

  try {
    M1 - M2;
    return false;
  }
  catch (const std::runtime_error& e) {
    return true;
  }
}

bool multiply_scalar_zero() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix Expected({{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}});

  return (M1*CNum(0,0)) == Expected;
}

bool multiply_scalar_real() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix Expected({{CNum(2,2), CNum(4,4)},{CNum(6,6), CNum(8,8)}});

  return (M1 * CNum(2,0)) == Expected;
}

bool multiply_scalar_imaginary() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix Expected({{CNum(-2,2), CNum(-4,4)},{CNum(-6,6), CNum(-8,8)}});

  return (M1 * CNum(0,2)) == Expected;
}

bool multiply_scalar_complex() {
  Matrix M1({{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}});
  Matrix Expected({{CNum(0,4), CNum(0,8)},{CNum(0,12), CNum(0,16)}});

  return (M1 * CNum(2,2)) == Expected;
}

bool multiply_matrix() {
  Matrix M1({{CNum(1,1), CNum(2,0)},{CNum(0,3), CNum(4,-1)}});
  Matrix M2({{CNum(5,0), CNum(6,-1)},{CNum(0,-7), CNum(8,0)}});
  Matrix Expected({{CNum(5,-9), CNum(23,5)},{CNum(-7,-13), CNum(35,10)}});

  return (M1 * M2) == Expected;
}

// TODO: Matrix tensorProduct(const Matrix& m2)


// TODO: Matrix complexConjugate() const


// TODO: Matrix transpose() const


// TODO: Matrix hermitianConjugate() const


// everything returns true at the moment so that I can test functionality
int main() {
  int totalPassed = 0;

  // define all the tests
  const std::vector<test_case> tests = {
    {add_normal, "Add Normal"},
    {add_wrong_dimension, "Add Wrong Dimension"},
    {sub_normal, "Subtract Normal"},
    {sub_wrong_dimension, "Subtract Wrong Dimension"},
    {multiply_scalar_zero, "Mutiply Scalar Zero"},
    {multiply_scalar_real, "Mutiply Scalar Real"},
    {multiply_scalar_imaginary, "Multiply Scalar Imaginary"},
    {multiply_scalar_complex, "Multiply Scalar Complex"}
  };

  std::cout << "=======================================" << std::endl;
  std::cout << "test_matrix: START" << std::endl;
  std::cout << std::endl;

  for (const test_case test : tests) {
    bool didPass = test.test_ptr();
    if (didPass) ++totalPassed;
    std::cout << test.test_name <<": " << ((didPass) ? "Passed" : "Failed") << std::endl;
  }

  std::cout << "Test Cases Passed: " << totalPassed << "/" << tests.size() << " ";
  std::cout << "(" << std::fixed << std::setprecision(2);
  std::cout << (static_cast<double>(totalPassed)/tests.size()) * 100.0 << "%)" << std::endl;

  std::cout << std::endl;
  std::cout << "test_matrix: END" << std::endl;
  std::cout << "=======================================" << std::endl;
}