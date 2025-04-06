#include "complexNumber.hpp"
#include <cmath>

CNum::CNum() : real(0), comp(0) {};

CNum::CNum(int r, int c) : real(r), comp(c) {};

CNum CNum::add(const CNum& cn2) const {
  return CNum(real + cn2.real, comp + cn2.comp);
}

CNum CNum::subtract(const CNum& cn2) const {
  return CNum(real - cn2.real, comp - cn2.comp);
}

CNum CNum::multiply(const CNum& cn2) const {
  return CNum((real * cn2.real) - (comp * cn2.comp), (real * cn2.comp) + (comp * cn2.real));
}

CNum CNum::complexConjugate() const {
  return CNum(real, -comp);
}

double CNum::magnitude() const {
  return std::sqrt(real * real + comp * comp);
}

std::string CNum::print() const {
  if (comp >= 0) {
    return "[" + std::to_string(real) + "+" + std::to_string(comp) + "i]";
  }

  return "[" + std::to_string(real) + std::to_string(comp) + "i]";  
}