#include "matrix.hpp"
#include <iostream>

// Matrix add(const Matrix& m2) const
bool add_normal() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(4,4), CNum(3,3)},{CNum(2,2), CNum(1,1)}};
  matrix m3 = {{CNum(5,5), CNum(5,5)},{CNum(5,5), CNum(5,5)}};
  Matrix M1(m1);
  Matrix M2(m2);
  Matrix Expected(m3);

  return true;
}

bool add_wrong_dimension() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

// Matrix subtract(const Matrix& m2) const
bool sub_normal() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m3 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);
  Matrix M2(m2);
  Matrix Expected(m3);

  return true;
}

bool sub_wrong_dimension() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);

  return true;
}

// Matrix scalarMultiply(const CNum& cn2) const
bool multiply_zero_scalar() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);
  Matrix Expected(m2);

  return true;
}

bool multiply_scalar_real() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(2,2), CNum(4,4)},{CNum(6,6), CNum(8,8)}};
  Matrix M1(m1);
  Matrix Expected(m2);

  return true;
}

bool multiply_scalar_imaginary() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(-2,2), CNum(-4,4)},{CNum(-6,6), CNum(-8,8)}};
  Matrix M1(m1);
  Matrix Expected(m2);

  return true;
}

bool multiply_scalar_complex() {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,4), CNum(0,8)},{CNum(0,12), CNum(0,16)}};
  Matrix M1(m1);
  Matrix Expected(m2);

  return true;
}

// Matrix matrixMultiply(const Matrix& m2) const


// Matrix tensorProduct(const Matrix& m2) const


// Matrix complexConjugate() const


// Matrix transpose() const


// Matrix hermitianConjugate() const


// bool ==


// bool !=


// main
int main() {
  std::cout << "test_matrix: START" << std::endl;
  

  std::cout << "test_matrix: END" << std::endl;
}