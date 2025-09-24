#include "operations.hpp"
#include "matrix.hpp"

#include <stdexcept>

// equals
bool operator==(const CNum& cnum1, const CNum& cnum2) {
  return ((cnum1.real == cnum2.real) && (cnum1.comp == cnum2.comp));
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.mat.size() != matrix2.mat.size() || matrix1.mat[0].size() != matrix2.mat[0].size()) {
    return false;
  }

  for (int i = 0; i < matrix1.mat.size(); i++) {
    for (int j = 0; j < matrix1.mat[0].size(); j++) {
      if (matrix1.mat[i][j] != matrix2.mat[i][j]) {
        return false;
      }
    }
  }

  return true;
}

// not equals
bool operator!=(const CNum& cnum1, const CNum& cnum2) {
  return ((cnum1.real != cnum2.real) || (cnum1.comp != cnum2.comp));
}

bool operator!=(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.mat.size() != matrix2.mat.size() || matrix1.mat[0].size() != matrix2.mat[0].size()) {
    return true;
  }

  for (int i = 0; i < matrix1.mat.size(); i++) {
    for (int j = 0; j < matrix1.mat[0].size(); j++) {
      if (matrix1.mat[i][j] != matrix2.mat[i][j]) {
        return true;
      }
    }
  }

  return false;
}


// addition
CNum operator+(const CNum& cnum1, const CNum& cnum2) {
  return CNum(cnum1.real + cnum2.real, cnum1.comp + cnum2.comp);
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.mat.size() != matrix2.mat.size() || matrix1.mat[0].size() != matrix2.mat[0].size()) {
    throw std::runtime_error("Matrix->add: Matrix dimensions do not match.");
  }
  
  t_matrix result(matrix1.mat.size(), t_rowVector(matrix1.mat[0].size()));

  for (int i = 0; i < matrix1.mat.size(); i++) {
    for (int j = 0; j < matrix1.mat[0].size(); j++) {
      result[i][j] = matrix1.mat[i][j] + matrix2.mat[i][j];
    }
  }

  return Matrix(result);
}

// subtraction
CNum operator-(const CNum& cnum1, const CNum& cnum2) {
  return CNum(cnum1.real - cnum2.real, cnum1.comp - cnum2.comp);
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.mat.size() != matrix2.mat.size() || matrix1.mat[0].size() != matrix2.mat[0].size()) {
    throw std::runtime_error("Matrix->sub: Matrix dimensions do not match.");
  }
  
  t_matrix result(matrix1.mat.size(), t_rowVector(matrix1.mat[0].size()));

  for (int i = 0; i < matrix1.mat.size(); i++) {
    for (int j = 0; j < matrix2.mat[0].size(); j++) {
      result[i][j] = matrix1.mat[i][j] - matrix2.mat[i][j];
    }
  }

  return Matrix(result);
}

// multiplication
CNum operator*(const CNum& cnum1, const CNum& cnum2) {
  return CNum((cnum1.real * cnum2.real) - (cnum1.comp * cnum2.comp), 
              (cnum1.real * cnum2.comp) + (cnum1.comp * cnum2.real));
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
  if (matrix1.mat[0].size() != matrix2.mat.size()) {
    throw std::runtime_error("Matrix->mult: Inner matrix dimensions do not match.");
  }

  t_matrix result(matrix1.mat.size(), t_rowVector(matrix2.mat[0].size()));

  #pragma omp parallel for collapse(2)
  for (int i = 0; i < matrix1.mat.size(); i++) {
    for (int j = 0; j < matrix2.mat[0].size(); j++) {
      CNum sum;
      for (int k = 0; k < matrix1.mat[0].size(); k++) {
        sum = sum + (matrix1.mat[i][k] * matrix2.mat[k][j]);
      }
      result[i][j] = sum;
    }
  }

  return Matrix(result);
}

Matrix operator*(const CNum& cnum, const Matrix& matrix) {
  t_matrix result = matrix.mat;

  for (t_rowVector& rv : result) {
    for (CNum& cn : rv) {
      cn = cn * cnum;
    }
  }

  return Matrix(result);
}

Matrix operator*(const Matrix& matrix, const CNum& cnum) {
  t_matrix result = matrix.mat;

  for (t_rowVector& rv : result) {
    for (CNum& cn : rv) {
      cn = cn * cnum;
    }
  }

  return Matrix(result);
}