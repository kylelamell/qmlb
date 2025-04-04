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
  virtual std::unique_ptr<BraKet> changeType() const = 0;
};

class Bra : public BraKet {
public:
  matrix state;
  Bra(matrix& s);
  std::unique_ptr<BraKet> changeType() const override;
};

class Ket : public BraKet {
public:
  matrix state;
  Ket(matrix& s);
  std::unique_ptr<BraKet> changeType() const override;
};

#endif