#include "matrix.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

struct test_case {
  bool (*test_ptr)();
  std::string test_name;
};

bool add_normal() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(4,4), CNum(3,3)},{CNum(2,2), CNum(1,1)}};
  matrix m3 = {{CNum(5,5), CNum(5,5)},{CNum(5,5), CNum(5,5)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

bool add_wrong_dimension() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

bool sub_normal() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m3 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

bool sub_wrong_dimension() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

bool multiply_scalar_zero() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);

  return true;
}

bool multiply_scalar_real() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(2,2), CNum(4,4)},{CNum(6,6), CNum(8,8)}};
  Matrix M1(m1);

  return true;
}

bool multiply_scalar_imaginary() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(-2,2), CNum(-4,4)},{CNum(-6,6), CNum(-8,8)}};
  Matrix M1(m1);

  return true;
}

bool multiply_scalar_complex() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,4), CNum(0,8)},{CNum(0,12), CNum(0,16)}};
  Matrix M1(m1);

  return true;
}

// Matrix matrixMultiply(const Matrix& m2) const


// Matrix tensorProduct(const Matrix& m2) const


// Matrix complexConjugate() const


// Matrix transpose() const


// Matrix hermitianConjugate() const


// bool ==


// bool !=

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