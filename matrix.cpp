#include "matrix.hpp"
#include <stdexcept>
#include <iostream>

using std::vector, std::runtime_error, std::cout, std::endl;

Matrix::Matrix() {}

Matrix::Matrix(matrix& mat2) : mat(mat2) {}

Matrix Matrix::add(Matrix& m2) {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw runtime_error("Matrix::add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), vector<CNum>(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].add(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::sub(Matrix& m2) {
  if (mat.size() != m2.mat.size() || mat[0].size() != m2.mat[0].size()) {
    throw runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), vector<CNum>(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].sub(m2.mat[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::mult(Matrix& m2) {
  if (mat[0].size() != m2.mat.size()) {
    throw runtime_error("Matrix->mult: Inner matrix dimentions do not match.");
  }

  matrix result(mat.size(), vector<CNum>(m2.mat[0].size()));

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

Matrix Matrix::compConj() {
  matrix result = mat;

  for (vector<CNum>& vec : result) {
    for (CNum& cn : vec) {
      cn = cn.compConj();
    }
  }

  return Matrix(result);
}

Matrix Matrix::transpose() {
  matrix result(mat[0].size(), vector<CNum>(mat.size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[j][i] = mat[i][j];
    }
  }

  return Matrix(result);
}

Matrix Matrix::hermConj() {
  return this->transpose().compConj();
}

void Matrix::print() {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      cout << mat[i][j].print() << " ";
    }
    cout << endl;
  }
}