#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBER_H

#include <string>

class CNum {
public:
  int real;
  int comp;

  CNum();
  CNum(int r, int c);

  CNum add(const CNum& cn2) const;
  CNum subtract(const CNum& cn2) const;
  CNum multiply(const CNum& cn2) const;

  CNum complexConjugate() const;
  double magnitude() const;

  std::string print() const;

  friend bool operator==(const CNum& lhs, const CNum& rhs);
  friend bool operator!=(const CNum& lhs, const CNum& rhs);
};

#endif