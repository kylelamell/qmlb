#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"

#include <vector>

using t_matrix = std::vector<std::vector<CNum>>;
using t_rowVector = std::vector<CNum>;

class Matrix {
public:
  t_matrix mat;

  Matrix();
  Matrix(t_matrix mat);

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