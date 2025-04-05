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
  CNum sub(const CNum& cn2) const;
  CNum mult(const CNum& cn2) const;

  CNum compConj() const;
  double magnitude() const;

  std::string print();
};

#endif