#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (!A) flag = INCORRECT_MATRIX;
  if (!flag && (A->columns < 1 || A->rows < 1)) flag = INCORRECT_MATRIX;
  if (!flag && s21_create_matrix(A->columns, A->rows, result))
    flag = INCORRECT_MATRIX;
  if (!flag) {
    for (int i = 0; i < A->columns; ++i)
      for (int j = 0; j < A->rows; ++j) result->matrix[i][j] = A->matrix[j][i];
  }
  return flag;
}