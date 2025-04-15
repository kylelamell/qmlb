#include "matrix.hpp"
#include <gtest/gtest.h>

// Matrix add(const Matrix& m2) const;
TEST(MatrixTest, Add) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  Matrix M1(m1);
  matrix m2 = {{CNum(4,4), CNum(3,3)},{CNum(2,2), CNum(1,1)}};
  Matrix M2(m2);

  matrix m3 = {{CNum(5,5), CNum(5,5)},{CNum(5,5), CNum(5,5)}};
  Matrix M3(m3);

  EXPECT_EQ(M1.add(M2), M3);
}

// Matrix subtract(const Matrix& m2) const;


// Matrix scalarMultiply(const CNum& cn2) const;


// Matrix matrixMultiply(const Matrix& m2) const;


// Matrix tensorProduct(const Matrix& m2) const;


// Matrix complexConjugate() const;


// Matrix transpose() const;


// Matrix hermitianConjugate() const;


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}