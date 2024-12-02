#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  bool equal = true;
  for (int i = 0; i < rows_ && equal; i++) {
    for (int j = 0; j < cols_ && equal; j++) {
      double diff = matrix_[i][j] - other.matrix_[i][j];
      diff = (diff < 0) ? diff * -1 : diff;
      if (diff > ERROR_RATE) {
        equal = false;
      }
    }
  }
  return equal;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  // except
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw DIFF_ERR;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  // except
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw DIFF_ERR;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    S21Matrix Buff(rows_, other.cols_);
    for (int m = 0; m < rows_; m++) {
      for (int n = 0; n < other.cols_; n++) {
        for (int k = 0; k < other.rows_; k++) {
          Buff.matrix_[m][n] += matrix_[m][k] * other.matrix_[k][n];
        }
      }
    }
    SetSize(rows_, other.cols_);
    MakeCopy(Buff);
  } else {
    throw "Матрицы не подходящей размерности";
  }
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix Buff(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      Buff.matrix_[j][i] = matrix_[i][j];
    }
  }
  return Buff;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix Result(*this);
  if (rows_ != cols_) {
    throw SQUARE_ERR;
  }
  for (int i = 0; i < rows_ && rows_ > 1; i++) {
    for (int j = 0; j < cols_; j++) {
      Result.matrix_[i][j] = mat_wo_intersection(i, j).Determinant();
      if ((i + j) % 2 != 0) {
        Result.matrix_[i][j] *= -1;
      }
    }
  }
  return Result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw SQUARE_ERR;
  }
  double dtrm = 0;
  if (rows_ > 1) {
    for (int c = 0; c < cols_; c++) {
      double buff_dtrm = (c % 2 == 0) ? 1 : -1;
      buff_dtrm *= mat_wo_intersection(0, c).Determinant() * matrix_[0][c];
      dtrm += buff_dtrm;
    }
  } else {
    dtrm = matrix_[0][0];
  }
  return dtrm;
}

S21Matrix S21Matrix::InverseMatrix() {
  double dtrm = Determinant();
  if (dtrm == 0.) {
    throw "Определитель матрицы равен нолю";
  }
  S21Matrix Inverse_Matrix((*this).CalcComplements().Transpose());
  Inverse_Matrix.MulNumber(1 / dtrm);
  return Inverse_Matrix;
}

S21Matrix S21Matrix::mat_wo_intersection(int i, int j) noexcept {
  S21Matrix Buff(rows_ - 1, rows_ - 1);
  int r = 0, c = 0;
  for (int m = 0; m < rows_; m++) {
    for (int n = 0; n < cols_; n++) {
      if (m != i && n != j) {
        Buff.matrix_[r][c] = matrix_[m][n];
        c++;
        if (c == Buff.GetCols()) {
          c = 0;
          r++;
        }
      }
    }
  }
  return Buff;
}
