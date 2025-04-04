#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"
#include <vector>

typedef std::vector<std::vector<CNum>> matrix;

class Matrix {
public:
  matrix m;

  Matrix(Matrix& m);

  Matrix add(Matrix& m2);
  Matrix sub(Matrix& m2);
  Matrix mult(Matrix& m2);

  Matrix compConj();
  Matrix trans();
  Matrix dagger();
};

#endif