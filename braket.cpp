#include "braket.hpp"

using std::unique_ptr, std::make_unique;

// BraKet definitions
BraKetType BraKet::getType() {
  return type;
}

// Bra definitions
Bra::Bra(Matrix& s) : state(s) {
  type = bra;
}

unique_ptr<BraKet> Bra::changeType() {
  return make_unique<Ket>(state.dagger());
}

// Ket definitions
Ket::Ket(Matrix& s) : state(s) {
  type = ket;
}

unique_ptr<BraKet> Ket::changeType() {
  return make_unique<Bra>(state.dagger());
}