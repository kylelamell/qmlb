#include "state.hpp"

State::State(Matrix& s) : state(s) {}

// destructor
State::~State() {}

// copy
State::State(const State& other) : state(other.state), braket(other.braket) {}

// copy assignment
State& State::operator=(const State& other) {
  if (this != &other) {
    state = other.state;
    braket = other.braket;
  }
  return *this;
}

// move
State::State(State&& other) noexcept : state(std::move(other.state)), braket(other.braket) {
  // TODO: find a way to do without vector move
}

// move assignment
State& State::operator=(State&& other) noexcept {
  if (this != &other) {
    // TODO: find a way to do without vector move
    state = std::move(other.state);
    braket = other.braket;
  }
  return *this;
}

void State::hermitianConjugate() { 
  braket = (braket = Bra) ? Ket : Bra;

  state = state.hermitianConjugate();
}