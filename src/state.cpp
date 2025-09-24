#include "state.hpp"

State::State(Matrix& s) : state(s) {}

State::~State() {}
State::State(const State& other) {}
State::State(State&& other) noexcept {}
State& State::operator=(const State& other) {}
State& State::operator=(State&& other) noexcept {}

void State::hermitianConjugate() { 
  braket = (braket = Bra) ? Ket : Bra;

  state = state.hermitianConjugate();
}