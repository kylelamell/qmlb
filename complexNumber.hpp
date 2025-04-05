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
  CNum sub(CNum& cn2);
  CNum mult(CNum& cn2);

  std::string print();
};

#endif