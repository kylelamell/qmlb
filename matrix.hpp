#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"
#include <vector>

typedef std::vector<std::vector<CNum>> matrix;
typedef std::vector<CNum> rowVector;

class Matrix {
public:
  matrix mat;

  Matrix();

  Matrix(matrix& m);

  Matrix add(const Matrix& m2) const;
  Matrix sub(const Matrix& m2) const;
  Matrix mult(const Matrix& m2) const;

  Matrix transpose() const;
  Matrix compConj() const;
  Matrix hermConj() const;

  void print() const;
};

#endif