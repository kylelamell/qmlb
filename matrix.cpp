#include "matrix.hpp"
#include <stdexcept>
#include <iostream>

using std::vector, std::runtime_error, std::cout, std::endl;

Matrix::Matrix() {}

Matrix::Matrix(matrix& mat2) : mat(mat2) {}

Matrix Matrix::add(Matrix& m2) {
  matrix mat2 = m2.mat;
  if (mat.size() != mat2.size() || mat[0].size() != mat2[0].size()) {
    throw runtime_error("Matrix::add: Matrix dimensions do not match.");
  }
  
  vector<vector<CNum>> result(mat.size(), vector<CNum>(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].add(mat2[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::sub(Matrix& m2) {
  matrix mat2 = m2.mat;
  if (mat.size() != mat2.size() || mat[0].size() != mat2[0].size()) {
    throw runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  vector<vector<CNum>> result(mat.size(), vector<CNum>(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].sub(mat2[i][j]);
    }
  }

  return Matrix(result);
}

Matrix Matrix::mult(Matrix& m2) {
  matrix mat2 = m2.mat;
  if (mat[0].size() != mat2.size()) {
    throw runtime_error("Matrix->mult: Inner matrix dimentions do not match.");
  }

  matrix result(mat.size(), vector<CNum>(mat2[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat2[0].size(); j++) {
      CNum sum;
      for (int k = 0; k < mat[0].size(); k++) {
        sum = sum.add(mat[i][k].mult(mat2[k][j]));
      }
      result[i][j] = sum;
    }
  }

  return Matrix(result);
}

Matrix Matrix::compConj() {
  return Matrix();
}

Matrix Matrix::trans() {
  return Matrix();
}

Matrix Matrix::dagger() {
  return Matrix();
}

void Matrix::print() {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      cout << mat[i][j].print() << " ";
    }
    cout << endl;
  }
}