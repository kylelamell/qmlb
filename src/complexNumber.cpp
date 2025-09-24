#include "complexNumber.hpp"
#include "operations.hpp"

#include <cmath>

CNum::CNum() : real(0), imag(0) {};

CNum::CNum(int r, int c) : real(r), imag(c) {};

// destructor
CNum::~CNum() {}

// copy
CNum::CNum(const CNum& other) : real(other.real), imag(other.imag) {}

// copy assignment
CNum& CNum::operator=(const CNum& other) {
  if (this != &other) {
    real = other.real;
    imag = other.imag;
  }
  return *this;
}

// move
CNum::CNum(CNum&& other) noexcept : real(other.real), imag(other.imag) {
  other.real = 0;
  other.imag = 0;
}

// move assignment
CNum& CNum::operator=(CNum&& other) noexcept {
  if (this != &other) {
    real = other.real;
    imag = other.imag;
    other.imag = 0;
    other.imag = 0;
  }
  return *this;
}

CNum CNum::complexConjugate() {
  return CNum(real,-imag);
}

double CNum::magnitude() {
  return std::sqrt((real * real) + (imag * imag));
}

std::string CNum::toString() {
  if (imag >= 0) {
    return "[" + std::to_string(real) + "+" + std::to_string(imag) + "i]";
  }

  return "[" + std::to_string(real) + std::to_string(imag) + "i]";  
}