#include "state.hpp"

State::State(Matrix& s) : state(s) {}

State State::hermitianConjugate() {
  State newState(state.hermitianConjugate());
  
  if (braket == Bra) {
    newState.setKet();
  }
  else if (braket == Ket) {
    newState.setBra();
  }

  return newState;
}

void State::setBra() {
  braket = Bra;
}

void State::setKet() {
  braket = Ket;
}

BraKet State::getBraKet() {
  return braket;
}