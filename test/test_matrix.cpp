#include "matrix.hpp"
#include <gtest/gtest.h>

// Matrix add(const Matrix& m2) const;
TEST(MatrixTest, AddNormal) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(4,4), CNum(3,3)},{CNum(2,2), CNum(1,1)}};
  matrix m3 = {{CNum(5,5), CNum(5,5)},{CNum(5,5), CNum(5,5)}};
  Matrix M1(m1);
  Matrix M2(m2);
  Matrix Expected(m3);
  EXPECT_EQ(M1.add(M2), Expected);
}

TEST(MatrixTest, AddWrongDimension) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);
  EXPECT_THROW(M1.add(M2), std::runtime_error);
}

// Matrix subtract(const Matrix& m2) const;
TEST(MatrixTest, SubtractNormal) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m3 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);
  Matrix M2(m2);
  Matrix Expected(m3);
  EXPECT_EQ(M1.subtract(M2), Expected);
}

TEST(MatrixTest, SubtractWrongDimension) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(1,1)},{CNum(2,2)}};
  Matrix M1(m1);
  Matrix M2(m2);
  EXPECT_THROW(M1.subtract(M2), std::runtime_error);
}

// Matrix scalarMultiply(const CNum& cn2) const;
TEST(MatrixTest, ScalarMultiplyZero) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,0), CNum(0,0)},{CNum(0,0), CNum(0,0)}};
  Matrix M1(m1);
  Matrix Expected(m2);
  EXPECT_EQ(M1.scalarMultiply(CNum(0,0)), Expected);
}

TEST(MatrixTest, ScalarMultiplyReal) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(2,2), CNum(4,4)},{CNum(6,6), CNum(8,8)}};
  Matrix M1(m1);
  Matrix Expected(m2);
  EXPECT_EQ(M1.scalarMultiply(CNum(2,0)), Expected);
}

TEST(MatrixTest, ScalarMultiplyImaginary) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(-2,2), CNum(-4,4)},{CNum(-6,6), CNum(-8,8)}};
  Matrix M1(m1);
  Matrix Expected(m2);
  EXPECT_EQ(M1.scalarMultiply(CNum(0,2)), Expected);
}

TEST(MatrixTest, ScalarMultiplyComplex) {
  matrix m1 = {{CNum(1,1), CNum(2,2)},{CNum(3,3), CNum(4,4)}};
  matrix m2 = {{CNum(0,4), CNum(0,8)},{CNum(0,12), CNum(0,16)}};
  Matrix M1(m1);
  Matrix Expected(m2);
  EXPECT_EQ(M1.scalarMultiply(CNum(2,2)), Expected);
}

// Matrix matrixMultiply(const Matrix& m2) const;


// Matrix tensorProduct(const Matrix& m2) const;


// Matrix complexConjugate() const;


// Matrix transpose() const;


// Matrix hermitianConjugate() const;


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}