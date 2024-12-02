#include "s21_matrix_oop.h"

TEST(Set, Rows) {
  S21Matrix A;
  A.FillMatrix();
  ASSERT_EQ(3, A.GetRows());
  A.SetRows(5);
  A.SetRows(5);
  ASSERT_EQ(5, A.GetRows());
  A.SetRows(2);
  ASSERT_EQ(2, A.GetRows());
}

TEST(Set, Cols) {
  S21Matrix A;
  A.FillMatrix();
  ASSERT_EQ(5, A.GetCols());
  A.SetCols(6);
  A.SetCols(6);
  ASSERT_EQ(6, A.GetCols());
  A.SetCols(3);
  ASSERT_EQ(3, A.GetCols());
}

TEST(Set, Size) {
  S21Matrix A(5, 7);
  A.FillMatrix();
  ASSERT_EQ(5, A.GetRows());
  ASSERT_EQ(7, A.GetCols());
  A.SetSize(6, 8);
  ASSERT_EQ(6, A.GetRows());
  ASSERT_EQ(8, A.GetCols());
  A.SetSize(4, 6);
  A.SetSize(4, 6);
  ASSERT_EQ(4, A.GetRows());
  ASSERT_EQ(6, A.GetCols());
  A.SetSize(2, 4);
  ASSERT_EQ(2, A.GetRows());
  ASSERT_EQ(4, A.GetCols());
  A.SetSize(4, 6);
  ASSERT_EQ(4, A.GetRows());
  ASSERT_EQ(6, A.GetCols());
}

TEST(EQUAL, TRUE) {
  S21Matrix A(6, 5);
  S21Matrix B(6, 5);
  B.SetNum(2, 2, ERROR_RATE);
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(EQUAL, FALSE) {
  S21Matrix A(6, 5);
  S21Matrix B(6, 5);
  S21Matrix C(2, 5);
  S21Matrix D(6, 2);
  B.SetNum(2, 2, ERROR_RATE + SMALL_INCREASE);
  ASSERT_FALSE(A.EqMatrix(B));
  ASSERT_FALSE(A.EqMatrix(C));
  ASSERT_FALSE(A.EqMatrix(D));
}

TEST(OPERATIONS, SUM) {
  S21Matrix A(6, 5);
  S21Matrix B(6, 5);
  B.SetNum(2, 2, ERROR_RATE);
  A.SumMatrix(B);
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(OPERATIONS, SUB) {
  S21Matrix A(6, 5);
  S21Matrix B(6, 5);
  S21Matrix C(6, 5);
  A.SetNum(2, 2, ERROR_RATE);
  B.SetNum(2, 2, ERROR_RATE);
  ASSERT_TRUE(A.EqMatrix(B));
  A.SubMatrix(B);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(OPERATIONS, MUL_NUM) {
  S21Matrix A(6, 5);
  S21Matrix B(6, 5);
  A.SetNum(2, 2, ERROR_RATE * 20);
  B.SetNum(2, 2, ERROR_RATE * 10);
  ASSERT_FALSE(A.EqMatrix(B));
  B.MulNumber(2);
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(OPERATIONS, MUL_MAT21) {
  S21Matrix A(2, 4);
  S21Matrix B(4, 5);
  A.SetNum(1, 1, 3.003);
  B.SetNum(1, 1, 7.007);
  A.MulMatrix(B);
  S21Matrix C(2, 5);
  C.SetNum(1, 1, 21.042021);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(OPERATIONS, MULMATS) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetNum(1, 1, 3.003);
  B.SetNum(1, 1, 7.007);
  A.MulMatrix(B);
  S21Matrix C(2, 2);
  C.SetNum(1, 1, 21.042021);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(RETURNS, TRANSPOSE) {
  S21Matrix A(3, 4);
  S21Matrix B(4, 3);
  A.SetNum(2, 2, 21);
  B.SetNum(2, 2, 21);
  S21Matrix C = A.Transpose();
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(HELP, DETERMINANTE11) {
  S21Matrix A(1, 1);
  A.FillMatrix();
  ASSERT_EQ(A.Determinant(), A.GetNum(0, 0));
}

TEST(HELP, DETERMINANTE44) {
  S21Matrix A(4, 4);
  A.FillMatrix();
  ASSERT_NEAR(A.Determinant(), -0.0598402, ERROR_RATE);
}

TEST(HELP, DETERMINANTE55) {
  S21Matrix A(5, 5);
  A.SetNum(0, 0, 3);
  A.SetNum(0, 1, 8);
  A.SetNum(0, 2, 9);
  A.SetNum(0, 3, 4);
  A.SetNum(0, 4, 2);

  A.SetNum(1, 0, 1);
  A.SetNum(1, 1, 2);
  A.SetNum(1, 2, 5);
  A.SetNum(1, 3, 2);
  A.SetNum(1, 4, 6);

  A.SetNum(2, 0, 2);
  A.SetNum(2, 1, 3);
  A.SetNum(2, 2, 1);
  A.SetNum(2, 3, 4);
  A.SetNum(2, 4, 7);

  A.SetNum(3, 0, 8);
  A.SetNum(3, 1, 9);
  A.SetNum(3, 2, 1);
  A.SetNum(3, 3, 2);
  A.SetNum(3, 4, 3);

  A.SetNum(4, 0, 5);
  A.SetNum(4, 1, 6);
  A.SetNum(4, 2, 9);
  A.SetNum(4, 3, 8);
  A.SetNum(4, 4, 7);

  ASSERT_EQ(A.Determinant(), 6304);
}

TEST(HELP, DETERMINANTE66) {
  S21Matrix A(6, 6);
  A.FillMatrix();
  ASSERT_EQ(A.Determinant(), -1574.152101772424);
}

TEST(HELP, MINOR) {
  S21Matrix A(3, 3);

  A.SetNum(0, 0, 8);
  A.SetNum(0, 1, 10);
  A.SetNum(0, 2, 2);

  A.SetNum(1, 0, 7);
  A.SetNum(1, 1, 9);
  A.SetNum(1, 2, 6);

  A.SetNum(2, 0, 2);
  A.SetNum(2, 1, 4);
  A.SetNum(2, 2, 1);

  ASSERT_EQ(A.Determinant(), -50);
}

TEST(HELP, CALCCOMPLEMENTS) {
  S21Matrix A(4, 4);
  A.SetNum(0, 0, 3);
  A.SetNum(0, 1, 8);
  A.SetNum(0, 2, 9);
  A.SetNum(0, 3, 4);

  A.SetNum(1, 0, 1);
  A.SetNum(1, 1, 2);
  A.SetNum(1, 2, 5);
  A.SetNum(1, 3, 2);

  A.SetNum(2, 0, 2);
  A.SetNum(2, 1, 3);
  A.SetNum(2, 2, 1);
  A.SetNum(2, 3, 4);

  A.SetNum(3, 0, 8);
  A.SetNum(3, 1, 9);
  A.SetNum(3, 2, 1);
  A.SetNum(3, 3, 2);

  S21Matrix B = A.CalcComplements();
  ASSERT_EQ(B.GetNum(0, 1), -126);
  S21Matrix J(1, 1);
  J.SetNum(0, 0, 21);
  S21Matrix K = J.CalcComplements();
  ASSERT_TRUE(J.EqMatrix(K));
  ASSERT_NO_THROW(A.CalcComplements());
  S21Matrix G(1, 1);
  ASSERT_NO_THROW(G.CalcComplements());
}

TEST(HELP, INVERSE0) {
  S21Matrix A(4, 4);
  A.SetNum(0, 0, 3);
  A.SetNum(0, 1, 8);
  A.SetNum(0, 2, 9);
  A.SetNum(0, 3, 4);

  A.SetNum(1, 0, 1);
  A.SetNum(1, 1, 2);
  A.SetNum(1, 2, 5);
  A.SetNum(1, 3, 2);

  A.SetNum(2, 0, 2);
  A.SetNum(2, 1, 3);
  A.SetNum(2, 2, 1);
  A.SetNum(2, 3, 4);

  A.SetNum(3, 0, 8);
  A.SetNum(3, 1, 9);
  A.SetNum(3, 2, 1);
  A.SetNum(3, 3, 2);

  S21Matrix B = A.InverseMatrix();
}

TEST(OVERLOADS, SUM) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix C(2, 2);
  A.FillMatrix();
  B.FillMatrix();
  C.FillMatrix();
  C.MulNumber(2);
  ASSERT_TRUE((A + B) == C);
}

TEST(OVERLOADS, SUB) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix C(2, 2);
  A.FillMatrix();
  B.FillMatrix();
  ASSERT_TRUE((A - B) == C);
}

TEST(OVERLOADS, MULNUM0) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.FillMatrix();
  B.FillMatrix();
  B.MulNumber(2);
  ASSERT_TRUE((A * 2) == B);
}

TEST(OVERLOADS, MULNUM1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.FillMatrix();
  B.FillMatrix();
  B.MulNumber(2);
  ASSERT_TRUE((2 * A) == B);
}

TEST(OVERLOADS, MULMATRICES) {
  S21Matrix A(1, 3);
  S21Matrix B(3, 1);
  A.SetNum(0, 0, 11);
  A.SetNum(0, 1, 12);
  A.SetNum(0, 2, 9);

  B.SetNum(0, 0, 5);
  B.SetNum(1, 0, 6);
  B.SetNum(2, 0, 7);
  S21Matrix C = A * B;
  ASSERT_TRUE(C.GetNum(0, 0) == 190);
}

TEST(OVERLOADS, MULMATRICES1) {
  S21Matrix A(2, 4);
  S21Matrix B(4, 3);
  A.FillMatrix();
  B.FillMatrix();
  ASSERT_NEAR((A * B).GetNum(1, 1), 0.0071140026, ERROR_RATE);
}

TEST(OVERLOADS, ASSIGN_EQUAL_SUM_SUB) {
  S21Matrix A, B, C, D;
  A.SetNum(1, 1, 1983);
  B = A;
  B = B;
  C += A;
  A -= C;
  ASSERT_TRUE(B == C);
  ASSERT_TRUE(A == D);
}

TEST(OVERLOADS, ASSIGN_MULS) {
  S21Matrix A(1, 3);
  S21Matrix B(3, 1);
  A.SetNum(0, 0, 11);
  A.SetNum(0, 1, 12);
  A.SetNum(0, 2, 9);

  B.SetNum(0, 0, 5);
  B.SetNum(1, 0, 6);
  B.SetNum(2, 0, 7);
  S21Matrix C = A * B;
  A *= B;
  S21Matrix D(B);
  B *= 2;
  D.MulNumber(2);
  ASSERT_TRUE(A == C);
  A.SetSize(1, 1);
  S21Matrix mv(move(A));
  mv.PrintAll();
  double **mat = mv.GetMatrix();
  mat[0][0] = 0;
  ASSERT_TRUE(B == D);
}

TEST(OVERLOADS, INDEXES) {
  S21Matrix A;
  A(2, 4) = 1;
  const S21Matrix B;
  ASSERT_TRUE(B(0, 0) == 0);
}

TEST(THROWS, ALL) {
  S21Matrix A(4, 3), B(4, 4), C(3, 3);
  const S21Matrix E(4, 3);
  ASSERT_ANY_THROW(S21Matrix A(-1, 1));
  ASSERT_ANY_THROW(S21Matrix A(1, -1));
  ASSERT_ANY_THROW(A.SetRows(0));
  ASSERT_ANY_THROW(A.SetCols(0));
  ASSERT_ANY_THROW(A.SetSize(0, 1));
  ASSERT_ANY_THROW(A.SetSize(1, 0));
  ASSERT_ANY_THROW(A.SetNum(-1, 0, 21.21));
  ASSERT_ANY_THROW(A.SetNum(0, -1, 21.21));
  ASSERT_ANY_THROW(A.Determinant());
  ASSERT_ANY_THROW(A.CalcComplements());
  ASSERT_ANY_THROW(A.InverseMatrix());
  ASSERT_ANY_THROW(B.InverseMatrix());
  ASSERT_ANY_THROW(A + B);
  ASSERT_ANY_THROW(A + C);
  ASSERT_ANY_THROW(A - B);
  ASSERT_ANY_THROW(A - C);
  ASSERT_ANY_THROW(A * B);
  ASSERT_ANY_THROW(A(-1, 2));
  ASSERT_ANY_THROW(A(3, -1));
  ASSERT_ANY_THROW(A(4, 2));
  ASSERT_ANY_THROW(A(3, 3));
  ASSERT_ANY_THROW(E(-1, 2));
  ASSERT_ANY_THROW(E(3, -1));
  ASSERT_ANY_THROW(E(4, 2));
  ASSERT_ANY_THROW(E(3, 3));
}

// helpfull methods for testing
void S21Matrix::PrintAll(void) noexcept {
  cout << rows_ << " " << cols_ << endl;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      cout << " \t" << setprecision(8) << matrix_[i][j];
    }
    cout << endl << endl;
  }
}

void S21Matrix::FillMatrix(void) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = i * cols_ + j;
    }
  }
  Decimal();
}

void S21Matrix::Decimal(void) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if ((i + j) % 2 == 0) {
        matrix_[i][j] += matrix_[i][j] * degree_of_ten(j);
      } else {
        matrix_[i][j] += matrix_[i][j] * degree_of_ten(rows_ - i - 1);
      }
      matrix_[i][j] *= ERROR_RATE;
    }
  }
}

int degree_of_ten(int extent) noexcept {
  int new_num = 10;
  for (int i = 0; i < extent; i++) {
    new_num *= new_num;
  }
  return new_num;
}
