#include "braket.hpp"

// BraKet definitions
BraKetType BraKet::getType() {
  return type;
}

// Bra definitions
Bra::Bra(Matrix& s) : state(s) {
  type = bra;
}

std::unique_ptr<BraKet> Bra::hermConj() {
  return std::make_unique<Ket>(state.hermConj());
}

// Ket definitions
Ket::Ket(Matrix& s) : state(s) {
  type = ket;
}

std::unique_ptr<BraKet> Ket::hermConj() {
  return std::make_unique<Bra>(state.hermConj());
}