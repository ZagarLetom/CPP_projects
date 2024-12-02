#include "../s21_matrix_oop.h"

// constructors
S21Matrix::S21Matrix() noexcept : rows_(3), cols_(5) { MemoryAllocate(); }

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
    MemoryAllocate();
  } else {
    throw SIZE_ERR;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) noexcept : rows_(other.rows_) {
  cols_ = other.cols_;
  MemoryAllocate();
  MakeCopy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept : rows_(other.rows_) {
  cols_ = other.cols_;
  MemoryAllocate();
  MakeCopy(other);
  other.~S21Matrix();
}

// destructor
S21Matrix::~S21Matrix() noexcept {
  MemoryFree();
  rows_ = 0;
  cols_ = 0;
}

// accessors
int S21Matrix::GetRows(void) const { return rows_; };
int S21Matrix::GetCols(void) const { return cols_; };
double** S21Matrix::GetMatrix(void) const { return matrix_; }
double S21Matrix::GetNum(int i, int j) const { return matrix_[i][j]; }

// mutators
void S21Matrix::SetRows(int new_rows) {
  if (new_rows > 0) {
    S21Matrix Buff(*this);
    MemoryFree();
    rows_ = new_rows;
    cols_ = Buff.cols_;
    MemoryAllocate();
    MakeCopy(Buff);
  } else {
    throw SIZE_ERR;
  }
}
void S21Matrix::SetCols(int new_cols) {
  if (new_cols > 0) {
    S21Matrix Buff(*this);
    MemoryFree();
    rows_ = Buff.rows_;
    cols_ = new_cols;
    MemoryAllocate();
    MakeCopy(Buff);
  } else {
    throw SIZE_ERR;
  }
}
void S21Matrix::SetNum(int i, int j, double num) {
  if (i >= 0 && j >= 0) {
    matrix_[i][j] = num;
  } else {
    throw INDEX_ERR;
  }
}
void S21Matrix::SetSize(int new_rows, int new_cols) {
  if (new_rows > 0 && new_cols > 0) {
    S21Matrix Buff(*this);
    MemoryFree();
    rows_ = new_rows;
    cols_ = new_cols;
    MemoryAllocate();
    MakeCopy(Buff);
  } else {
    throw SIZE_ERR;
  }
}

// helpfull function for decompose the code
void S21Matrix::MemoryAllocate(void) noexcept {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}
void S21Matrix::MemoryFree(void) noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::MakeCopy(const S21Matrix& other) noexcept {
  for (int i = 0; i < rows_ && i < other.GetRows(); i++) {
    for (int j = 0; j < cols_ && j < other.GetCols(); j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
