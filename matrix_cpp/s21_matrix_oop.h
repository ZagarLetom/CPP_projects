#ifndef __S21_MATRIX_OOP__H
#define __S21_MATRIX_OOP__H
#include <gtest/gtest.h>

#include <iostream>
using namespace std;
#define ERROR_RATE 1e-07
#define SMALL_INCREASE 1e-21
#define DIFF_ERR "Размеры матриц не равны друг другу."
#define SIZE_ERR "Размер матрицы не может быть меньше 1x1."
#define INDEX_ERR "Индекс матрицы не может быть меньше 0х0."
#define SQUARE_ERR "Для этой операции матрица должна быть квадратной."
int degree_of_ten(int extent) noexcept;
class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // Structors
  S21Matrix(void) noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix(void) noexcept;

  // Base operations
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose(void) noexcept;
  double Determinant(void);
  S21Matrix CalcComplements(void);
  S21Matrix InverseMatrix(void);

  // Overloads
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  friend S21Matrix operator*(double num, S21Matrix& other);
  friend S21Matrix operator*(S21Matrix& other, double num);

  bool operator==(const S21Matrix& other);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);

  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);

  // Accessors
  int GetRows(void) const;
  int GetCols(void) const;
  double GetNum(int i, int j) const;
  double** GetMatrix(void) const;

  // Mutators
  void SetRows(int new_rows);
  void SetCols(int new_cols);
  void SetNum(int i, int j, double num);
  void SetSize(int new_rows, int new_cols);

  // Help to core
  void MemoryAllocate(void) noexcept;
  void MemoryFree(void) noexcept;
  void MakeCopy(const S21Matrix& other) noexcept;
  S21Matrix mat_wo_intersection(int i, int j) noexcept;

  // Help to test
  void FillMatrix(void) noexcept;
  void PrintAll(void) noexcept;
  void Decimal(void) noexcept;
};

// выносим перегрузку оператора умножения на число вне класса для
// возможности умножать как число на матрицу, так и матрицу на число
S21Matrix operator*(double num, S21Matrix& other);
S21Matrix operator*(S21Matrix& other, double num);

#endif
