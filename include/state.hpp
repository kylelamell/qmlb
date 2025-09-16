#ifndef STATE_H
#define STATE_H

#include "matrix.hpp"
#include <memory>
#include <string>

enum BraKet {Bra, Ket};

class State {
private:
  BraKet braket;

public:
  Matrix state;

  State(Matrix& s);

  State hermitianConjugate();

  void setBra();
  void setKet();

  BraKet getBraKet();
};

#endif