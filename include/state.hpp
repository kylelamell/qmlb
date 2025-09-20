#ifndef STATE_H
#define STATE_H

#include "matrix.hpp"
#include <memory>
#include <string>

enum BraKet {Bra, Ket};

class State {
public:
  Matrix state;
  BraKet braket;

  State(Matrix& s);

  void hermitianConjugate();
};

#endif