#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"
#include <vector>

using matrix = std::vector<std::vector<CNum>>;
using rowVector = std::vector<CNum>;

class Matrix {
public:
  matrix mat;

  Matrix();
  Matrix(matrix& m);

  ~Matrix();
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&& other) noexcept;
 
  Matrix tensorProduct(Matrix& m2);

  Matrix transpose();
  Matrix complexConjugate();
  Matrix hermitianConjugate();

  void print();

  Matrix operator+(const Matrix& other);
  Matrix operator-(const Matrix& other);
  Matrix operator*(const CNum& scalar);
  Matrix operator*(const Matrix& other);
  bool operator==(const Matrix& other);
  bool operator!=(const Matrix& other);
};

#endif