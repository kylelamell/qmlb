#ifndef BRAKET_H
#define BRAKET_H

#include "matrix.hpp"
#include <memory>

enum BraKetType {bra, ket};

class BraKet {
protected:
  BraKetType type;
public:
  virtual ~BraKet() {};
  BraKetType getType();
  virtual std::unique_ptr<BraKet> hermConj() = 0;
};

class Bra : public BraKet {
public:
  Matrix state;
  Bra(Matrix& s);
  std::unique_ptr<BraKet> hermConj() override;
};

class Ket : public BraKet {
public:
  Matrix state;
  Ket(Matrix& s);
  std::unique_ptr<BraKet> hermConj() override;
};

#endif