#ifndef BRAKET_H
#define BRAKET_H

#include "matrix.hpp"
#include <memory>

enum BraKetType {bra, ket};

class Bra {
public:
  Matrix state;
  Bra(Matrix& s);

  Ket hermitianConjugate();
};

class Ket {
public:
  Matrix state;
  Ket(Matrix& s);

  Bra hermitianConjugate();
};

#endif