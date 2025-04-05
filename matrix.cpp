#include "matrix.hpp"
#include <stdexcept>
#include <iostream>

Matrix::Matrix() {}

Matrix::Matrix(matrix& mat2) : mat(mat2) {}

Matrix Matrix::add(const Matrix& m2) const {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw std::runtime_error("Matrix::add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].add(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::sub(const Matrix& m2) const {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw std::runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].sub(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::mult(const Matrix& m2) const {
  if (mat[0].size() != m2.mat.size()) {
    throw std::runtime_error("Matrix->mult: Inner matrix dimentions do not match.");
  }

  matrix result(mat.size(), rowVector(m2.mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < m2.mat[0].size(); j++) {
      CNum sum;
      for (int k = 0; k < mat[0].size(); k++) {
        sum = sum.add(mat[i][k].mult(m2.mat[k][j]));
      }
      result[i][j] = sum;
    }
  }

  return Matrix(result);
}

Matrix Matrix::compConj() const {
  matrix result = mat;

  for (rowVector& vec : result) {
    for (CNum& cn : vec) {
      cn = cn.compConj();
    }
  }

  return Matrix(result);
}

Matrix Matrix::transpose() const {
  matrix result(mat[0].size(), rowVector(mat.size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[j][i] = mat[i][j];
    }
  }

  return Matrix(result);
}

Matrix Matrix::hermConj() const {
  return this->transpose().compConj();
}

void Matrix::print() const {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      std::cout << mat[i][j].print() << " ";
    }
    std::cout << std::endl;
  }
}