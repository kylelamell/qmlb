#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBER_H

#include <string>

class CNum {
public:
  int real;
  int comp;

  CNum();
  CNum(int r, int c);

  CNum add(CNum& cn2);
  CNum subtract(CNum& cn2);
  CNum multiply(CNum& cn2);

  CNum complexConjugate();
  double magnitude();

  std::string print();

  friend bool operator==(CNum& lhs, CNum& rhs);
  friend bool operator!=(CNum& lhs, CNum& rhs);
};

#endif