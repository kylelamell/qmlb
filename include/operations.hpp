#ifndef OPERATIONS_H
#define OPERATIONS_H

class CNum;
class Matrix;

// boolean operations
bool operator==(const CNum& cnum1, const CNum& cnum2);
bool operator!=(const CNum& cnum1, const CNum& cnum2);
bool operator!=(const Matrix& matrix1, const Matrix& matrix2);
bool operator==(const Matrix& matrix1, const Matrix& matrix2);

// addition operations
CNum operator+(const CNum& cnum1, const CNum& cnum2);
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);

// subtraction operations
CNum operator-(const CNum& cnum1, const CNum& cnum2);
Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);

// multiplication operations
CNum operator*(const CNum& cnum1, const CNum& cnum2);
Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(const CNum& cnum, const Matrix& matrix);
Matrix operator*(const Matrix& matrix, const CNum& cnum);

#endif