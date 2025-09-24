#ifndef STATE_H
#define STATE_H

#include "matrix.hpp"

enum BraKet {Bra, Ket};

class State {
public:
  Matrix state;
  BraKet braket;

  State();
  State(Matrix& s);

  ~State();
  State(const State& other);
  State(State&& other) noexcept;
  State& operator=(const State& other);
  State& operator=(State&& other) noexcept;

  void hermitianConjugate();
};

#endif