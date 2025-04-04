#ifndef MATRIX_H
#define MATRIX_H

#include "complexNumber.hpp"
#include <vector>

typedef std::vector<std::vector<CNum>> matrix;

class Matrix {
public:
  matrix m;

  Matrix(matrix& m);

  matrix add(matrix& m2);
  matrix sub(matrix& m2);
  matrix mult(matrix& m2);

  matrix compConj();
  matrix trans();
  matrix dag();
};

#endif