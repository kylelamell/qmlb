#include "complexNumber.hpp"

using std::string;

CNum::CNum() : real(0), comp(0) {};

CNum::CNum(int r, int c) : real(r), comp(c) {};

CNum CNum::add(CNum& cn2) {
  return CNum(real + cn2.real, comp + cn2.comp);
}

CNum CNum::sub(CNum& cn2) {
  return CNum(real - cn2.real, comp - cn2.comp);
}

CNum CNum::mult(CNum& cn2) {
  return CNum((real * cn2.real) - (comp * comp), (real * cn2.comp) + (comp * cn2.real));
}

string CNum::print() {
  return "[" + std::to_string(real) + "+" + std::to_string(comp) + "i]";
}