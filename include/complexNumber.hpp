#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBER_H

#include <string>

class CNum {
public:
  int real;
  int comp;

  CNum();
  CNum(int r, int c);

  ~CNum();
  CNum(const CNum& other);
  CNum(CNum&& other) noexcept;
  CNum& operator=(const CNum& other);
  CNum& operator=(CNum&& other) noexcept;

  CNum complexConjugate();
  double magnitude();

  std::string toString();

  CNum operator+(const CNum& other);
  CNum operator-(const CNum& other);
  CNum operator*(const CNum& other);
  bool operator==(const CNum& other);
  bool operator!=(const CNum& other);
};

#endif