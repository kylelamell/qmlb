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

  Matrix add(Matrix& m2);
  Matrix sub(Matrix& m2);
  Matrix mult(Matrix& m2);

  Matrix transpose();
  Matrix compConj();
  Matrix hermConj();

  void print();
};

#endif