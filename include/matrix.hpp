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

  Matrix add(Matrix& m2);
  Matrix subtract(Matrix& m2);

  Matrix scalarMultiply(CNum& cn2);
  Matrix matrixMultiply(Matrix& m2);
  
  Matrix tensorProduct(Matrix& m2);

  Matrix transpose();
  Matrix complexConjugate();
  Matrix hermitianConjugate();

  void print();

  friend bool operator==(Matrix& lhs, Matrix& rhs);
  friend bool operator!=(Matrix& lhs, Matrix& rhs);
};

#endif