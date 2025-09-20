#include "state.hpp"

State::State(Matrix& s) : state(s) {}

void State::hermitianConjugate() { 
  braket = (braket = Bra) ? Ket : Bra;

  state = state.hermitianConjugate();
}