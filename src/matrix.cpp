#include "matrix.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

Matrix::Matrix() {}
Matrix::Matrix(matrix mat) : mat(mat) {}

// destructor
Matrix::~Matrix() {}

// copy
// Matrix::Matrix(const Matrix& other) : mat(other.mat) {}
Matrix::Matrix(const Matrix& other) {
  mat.resize(other.mat.size());
  for (int i = 0; i < other.mat.size(); i++) {
    mat[i].resize(other.mat[i].size());
    for (int j = 0; j < other.mat[i].size(); j++) {
      mat[i][j] = other.mat[i][j];
    }
  }
}

// copy assingment
// Matrix& Matrix::operator=(const Matrix& other) {
//   if (this != &other) {
//     mat = other.mat;
//   }
//   return *this;
// }
Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    mat.resize(other.mat.size());
    for (int i = 0; i < other.mat.size(); i++) {
      mat[i].resize(other.mat[i].size());
      for (int j = 0; j < other.mat[i].size(); j++) {
        mat[i][j] = other.mat[i][j];
      }
    }
  }
  return *this;
}

// move
Matrix::Matrix(Matrix&& other) noexcept : mat(std::move(other.mat)) {
  // TODO: find a way to do without vector move
}

// move assignment
Matrix& Matrix::operator=(Matrix&& other) noexcept {
  if (this != &other) {
    // TODO: find a way to do without vector move
    mat = std::move(other.mat);
  }
  return *this;
}

Matrix Matrix::tensorProduct(const Matrix& other) {
  matrix result(mat.size() * other.mat.size(), rowVector(mat[0].size() * other.mat[0].size()));

  // loop over left matrix
  #pragma omp parallel for collapse(4)
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      // for each element in left matrix: loop over right matrix
      for (int u = 0; u < other.mat.size(); u++) {
        for (int v = 0; v < other.mat[0].size(); v++) {
          result[(i * other.mat.size()) + u][(j * other.mat[0].size()) + v] 
            = mat[i][j] * other.mat[u][v];
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
      std::cout << mat[i][j].toString() << " ";
    }
    std::cout << std::endl;
  }
}

Matrix Matrix::operator+(const Matrix& other) {
  if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
    throw std::runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j] + other.mat[i][j];
    }
  }

  return Matrix(result);
}

Matrix Matrix::operator-(const Matrix& other) {
  if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
    throw std::runtime_error("Matrix->sub: Matrix dimensions do not match.");
  }
  
  matrix result(mat.size(), rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j] - other.mat[i][j];
    }
  }

  return Matrix(result);
}

Matrix Matrix::operator*(const CNum& scalar) {
  matrix result = mat;

  for (rowVector& vec : result) {
    for (CNum& cn : vec) {
      cn = cn * scalar;
    }
  }

  return result;
}

Matrix Matrix::operator*(const Matrix& other) {
  if (mat[0].size() != other.mat.size()) {
    throw std::runtime_error("Matrix->mult: Inner matrix dimensions do not match.");
  }

  matrix result(mat.size(), rowVector(other.mat[0].size()));

  #pragma omp parallel for collapse(2)
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < other.mat[0].size(); j++) {
      CNum sum;
      for (int k = 0; k < mat[0].size(); k++) {
        sum = sum + (mat[i][k] * other.mat[k][j]);
      }
      result[i][j] = sum;
    }
  }

  return Matrix(result);
}

bool Matrix::operator==(const Matrix& other) {
  if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
    return false;
  }

  for (int i = 0; i < other.mat.size(); i++) {
    for (int j = 0; j < other.mat[0].size(); j++) {
      if (mat[i][j] != other.mat[i][j]) {
        return false;
      }
    }
  }

  return true;
}

bool Matrix::operator!=(const Matrix& other) {
  if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
    return true;
  }

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      if (mat[i][j] != other.mat[i][j]) {
        return true;
      }
    }
  }

  return false;
}