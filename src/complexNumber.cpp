#include "complexNumber.hpp"
#include <cmath>

CNum::CNum() : real(0), comp(0) {};

CNum::CNum(int r, int c) : real(r), comp(c) {};

// destructor
CNum::~CNum() {}

// copy
CNum::CNum(const CNum& other) : real(other.real), comp(other.comp) {}

// copy assignment
CNum& CNum::operator=(const CNum& other) {
  if (this != &other) {
    real = other.real;
    comp = other.comp;
  }
  return *this;
}

// move
CNum::CNum(CNum&& other) noexcept : real(other.real), comp(other.comp) {
  other.real = 0;
  other.comp = 0;
}

// move assignment
CNum& CNum::operator=(CNum&& other) noexcept {
  if (this != &other) {
    real = other.real;
    comp = other.comp;
    other.comp = 0;
    other.comp = 0;
  }
  return *this;
}

CNum CNum::complexConjugate() {
  return CNum(real, -comp);
}

double CNum::magnitude() {
  return std::sqrt(real * real + comp * comp);
}

std::string CNum::toString() {
  if (comp >= 0) {
    return "[" + std::to_string(real) + "+" + std::to_string(comp) + "i]";
  }

  return "[" + std::to_string(real) + std::to_string(comp) + "i]";  
}

CNum CNum::operator+(const CNum& other) {
  return CNum(real + other.real, comp + other.comp);
}

CNum CNum::operator-(const CNum& other) {
  return CNum(real - other.real, comp - other.comp);
}

CNum CNum::operator*(const CNum& other) {
  return CNum((real * other.real) - (comp * other.comp), (real * other.comp) + (comp * other.real));
}

bool CNum::operator==(const CNum& other) {
  return ((real == other.real) && (comp == other.comp));
}

bool CNum::operator!=(const CNum& other) {
  return ((real != other.real) || (comp != other.comp));
}