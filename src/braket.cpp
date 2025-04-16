#include "braket.hpp"

// Bra definitions
Bra::Bra(Matrix& s) : state(s) {}

Ket Bra::hermitianConjugate() {
  return Ket(state.hermitianConjugate());
}

// Ket definitions
Ket::Ket(Matrix& s) : state(s) {}

Bra Ket::hermitianConjugate() {
  return Bra(state.hermitianConjugate());
}