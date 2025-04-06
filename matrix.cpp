#include "matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Matrix::Matrix() {}

Matrix::Matrix(matrix& mat2) : mat(mat2) {}

Matrix Matrix::add(const Matrix& m2) const {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw std::runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].add(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::subtract(const Matrix& m2) const {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw std::runtime_error("Matrix->sub: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].subtract(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::multiply(const Matrix& m2) const {
  if (mat[0].size() != m2.mat.size()) {
    throw std::runtime_error("Matrix->mult: Inner matrix dimentions do not match.");
  }

  matrix result(mat.size(), rowVector(m2.mat[0].size()));

  // googled how to parallel this and this came up
  #pragma omp parallel for collapse(2)
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < m2.mat[0].size(); j++) {
      CNum sum;
      for (int k = 0; k < mat[0].size(); k++) {
        sum = sum.add(mat[i][k].multiply(m2.mat[k][j]));
      }
      result[i][j] = sum;
    }
  }

  return Matrix(result);
}

#pragma omp parallel for collapse(4)
Matrix Matrix::tensorProduct(const Matrix& m2) const {
  matrix result(mat.size() * m2.mat.size(), rowVector(mat[0].size() * m2.mat[0].size()));

  // loop over left matrix
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      // for ech element: loop over right matrix
      for (int u = 0; u < m2.mat.size(); u++) {
        for (int v = 0; v < m2.mat[0].size(); v++) {
          result[(i * m2.mat.size()) + u][(j * m2.mat[0].size()) + v] = mat[i][j].multiply(m2.mat[u][v]);
        }
      }
    }
  }

  return result;
}

Matrix Matrix::complexConjugate() const {
  matrix result = mat;

  for (rowVector& vec : result) {
    for (CNum& cn : vec) {
      cn = cn.complexConjugate();
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

Matrix Matrix::hermitianConjugate() const {
  return this->transpose().complexConjugate();
}

void Matrix::print() const {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      std::cout << mat[i][j].print() << " ";
    }
    std::cout << std::endl;
  }
}