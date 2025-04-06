#include "braket.hpp"

// BraKet definitions
BraKetType BraKet::getType() {
  return type;
}

// Bra definitions
Bra::Bra(Matrix& s) : state(s) {
  type = bra;
}

std::unique_ptr<BraKet> Bra::hermitianConjugate() {
  return std::make_unique<Ket>(state.hermitianConjugate());
}

// Ket definitions
Ket::Ket(Matrix& s) : state(s) {
  type = ket;
}

std::unique_ptr<BraKet> Ket::hermitianConjugate() {
  return std::make_unique<Bra>(state.hermitianConjugate());
}