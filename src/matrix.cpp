#include "matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Matrix::Matrix() {}

Matrix::Matrix(matrix& mat2) : mat(mat2) {}

Matrix Matrix::add(Matrix& m2) {
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

Matrix Matrix::subtract(Matrix& m2) {
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

Matrix Matrix::scalarMultiply(CNum& cn2) {
  matrix result = mat;

  for (rowVector& vec : result) {
    for (CNum& cn : vec) {
      cn = cn.multiply(cn2);
    }
  }

  return result;
}

Matrix Matrix::matrixMultiply(Matrix& m2) {
  if (mat[0].size() != m2.mat.size()) {
    throw std::runtime_error("Matrix->mult: Inner matrix dimensions do not match.");
  }

  matrix result(mat.size(), rowVector(m2.mat[0].size()));

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

Matrix Matrix::tensorProduct(Matrix& m2) {
  matrix result(mat.size() * m2.mat.size(), rowVector(mat[0].size() * m2.mat[0].size()));

  // loop over left matrix
  #pragma omp parallel for collapse(4)
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      // for each element in left matrix: loop over right matrix
      for (int u = 0; u < m2.mat.size(); u++) {
        for (int v = 0; v < m2.mat[0].size(); v++) {
          result[(i * m2.mat.size()) + u][(j * m2.mat[0].size()) + v] = mat[i][j].multiply(m2.mat[u][v]);
        }
      }
    }
  }

  return result;
}

Matrix Matrix::complexConjugate() {
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].complexConjugate();
    }
  }

  return Matrix(result);
}

Matrix Matrix::transpose() {
  matrix result(mat[0].size(), rowVector(mat.size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[j][i] = mat[i][j];
    }
  }

  return Matrix(result);
}

Matrix Matrix::hermitianConjugate() {
  return this->transpose().complexConjugate();
}

void Matrix::print() {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      std::cout << mat[i][j].print() << " ";
    }
    std::cout << std::endl;
  }
}

bool operator==(Matrix& lhs, Matrix& rhs) {
  if (lhs.mat.size() != rhs.mat.size() || lhs.mat[0].size() != rhs.mat[0].size()) {
    return false;
  }

  for (int i = 0; i < lhs.mat.size(); i++) {
    for (int j = 0; j < lhs.mat[0].size(); j++) {
      if (lhs.mat[i][j] != rhs.mat[i][j]) {
        return false;
      }
    }
  }

  return true;
}

bool operator!=(Matrix& lhs, Matrix& rhs) {
  if (lhs.mat.size() != rhs.mat.size() || lhs.mat[0].size() != rhs.mat[0].size()) {
    return true;
  }

  for (int i = 0; i < lhs.mat.size(); i++) {
    for (int j = 0; j < lhs.mat[0].size(); j++) {
      if (lhs.mat[i][j] != rhs.mat[i][j]) {
        return true;
      }
    }
  }

  return false;
}