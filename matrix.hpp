#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"
#include <vector>

typedef std::vector<std::vector<CNum>> matrix;

class Matrix {
public:
  matrix mat;

  Matrix();

  Matrix(matrix& m);

  Matrix add(Matrix& m2);
  Matrix sub(Matrix& m2);
  Matrix mult(Matrix& m2);

  Matrix trans();
  Matrix compConj();
  Matrix hermConj();

  void print();
};

#endif