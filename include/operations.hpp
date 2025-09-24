#ifndef OPERATIONS_H
#define OPERATIONS_H

class CNum;
class Matrix;

// equals
bool operator==(const CNum& cnum1, const CNum& cnum2);
bool operator==(const Matrix& matrix1, const Matrix& matrix2);

// not equals
bool operator!=(const CNum& cnum1, const CNum& cnum2);
bool operator!=(const Matrix& matrix1, const Matrix& matrix2);

// addition
CNum operator+(const CNum& cnum1, const CNum& cnum2);
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);

// subtraction
CNum operator-(const CNum& cnum1, const CNum& cnum2);
Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);

// multiplication
CNum operator*(const CNum& cnum1, const CNum& cnum2);
Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(const CNum& cnum, const Matrix& matrix);
Matrix operator*(const Matrix& matrix, const CNum& cnum);

#endif