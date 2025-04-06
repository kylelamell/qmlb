#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <string>

// Matrix add(const Matrix& m2) const;
void run_test_add(const Matrix& m1, const Matrix& m2, const Matrix& ex, const std::string& testName) {
  // TODO: implement add test runner
  return; 
}
void test_add() {
  // TODO: implement add test
  return;
}

// Matrix subtract(const Matrix& m2) const;
void run_test_subtract(const Matrix& m1, const Matrix& m2, const Matrix& ex, const std::string& testName) {
  // TODO: implement subtract test runner
  return; 
}
void test_subtract() {
  // TODO: implement subtract test
  return;
}

// Matrix scalarMultiply(const CNum& cn2) const;
void run_test_scalarMultiply(const Matrix& m1, const CNum& cn2, const Matrix& ex, const std::string& testName) {
  // TODO: implement scalarMultiply test runner
  return;
}
void test_scalarMultiply() {
  // TODO: implement scalarMultiply test
  return;
}

// Matrix matrixMultiply(const Matrix& m2) const;
void run_test_matrixMultiply(const Matrix& m1, const Matrix& m2, const Matrix& ex, const std::string& testName) {
  // TODO: implement matrixMultiply test runner
  return;
}
void test_matrixMutiply() {
  // TODO: implement matrixMultiply test
  return;
}

// Matrix tensorProduct(const Matrix& m2) const;
void run_test_tensorProduct(const Matrix& m1, const Matrix& m2, const Matrix& ex, const std::string& testName) {
  // TODO: implement tensorProduct test runner
  return;
}
void test_tensorProduct() {
  // TODO: implement tensorPorduct test
  return;
}

// Matrix complexConjugate() const;
void run_test_complexConjugate(const Matrix& m1, const Matrix& ex, const std::string& testName) {
  // TODO: implement complexConjugate test runner
  return; 
}
void test_complexConjugate() {
  // TODO: implement complexConjugate test
  return;
}

// Matrix transpose() const;
void run_test_transpose(const Matrix& m1, const Matrix& ex, const std::string& testName) {
  // TODO: implement transpose test runner
  return; 
}
void test_transpose() {
  // TODO: implement transpose test
  return;
}

// Matrix hermitianConjugate() const;
void run_test_hermitianConjugate(const Matrix& m1, const Matrix& ex, const std::string& testName) {
  // TODO: implement hermitianConjugate test runner
  return; 
}
void test_hermitianConjugate() {
  // TODO: implement hermitianConjugate test
  return;
}

int main() {
  test_add();
  test_subtract();

  test_scalarMultiply();
  test_matrixMutiply();

  test_tensorProduct();

  test_complexConjugate();
  test_transpose();
  test_hermitianConjugate();

  return 0;
}