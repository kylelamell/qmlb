#include "matrix.hpp"
#include "operations.hpp"

#include <iostream>
#include <string>

Matrix::Matrix() {}
Matrix::Matrix(t_matrix mat) : mat(mat) {}

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
  t_matrix result(mat.size() * other.mat.size(), t_rowVector(mat[0].size() * other.mat[0].size()));

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
  t_matrix result(mat.size(), t_rowVector(mat[0].size()));

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      result[i][j] = mat[i][j].complexConjugate();
    }
  }

  return Matrix(result);
}

Matrix Matrix::transpose() {
  t_matrix result(mat[0].size(), t_rowVector(mat.size()));

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