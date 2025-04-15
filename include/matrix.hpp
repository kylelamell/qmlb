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

  Matrix add(const Matrix& m2) const;
  Matrix subtract(const Matrix& m2) const;

  Matrix scalarMultiply(const CNum& cn2) const;
  Matrix matrixMultiply(const Matrix& m2) const;
  
  Matrix tensorProduct(const Matrix& m2) const;

  Matrix transpose() const;
  Matrix complexConjugate() const;
  Matrix hermitianConjugate() const;

  void print() const;

  friend bool operator==(const Matrix& lhs, const Matrix& rhs);
  friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
};

#endif