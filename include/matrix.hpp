#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"

#include <vector>

using matrix_t = std::vector<std::vector<CNum>>;
using rowVector_t = std::vector<CNum>;

class Matrix {
public:
  matrix_t mat;

  Matrix();
  Matrix(matrix_t mat);

  ~Matrix();
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&& other) noexcept;
 
  Matrix tensorProduct(const Matrix& other);

  Matrix transpose();
  Matrix complexConjugate();
  Matrix hermitianConjugate();

  void print();
};

#endif