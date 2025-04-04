#include "braket.hpp"

using std::unique_ptr, std::make_unique;

// BraKet definitions
BraKetType BraKet::getType() {
  return type;
}

// Bra definitions
Bra::Bra(matrix& s) : state(s) {
  type = bra;
}

unique_ptr<BraKet> Bra::changeType() const {
  return make_unique<Ket>(state);
}

// Ket definitions
Ket::Ket(matrix& s) : state(s) {
  type = ket;
}

unique_ptr<BraKet> Ket::changeType() const {
  return make_unique<Bra>(state);
}