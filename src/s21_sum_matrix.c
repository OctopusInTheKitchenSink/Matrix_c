#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!A || !B)
    flag = INCORRECT_MATRIX;
  else {
    if (A->rows != B->rows || A->columns != B->columns)
      flag = CALCULATION_ERROR;
    if (!flag &&
        (A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1))
      flag = INCORRECT_MATRIX;
    if (!flag && s21_create_matrix(A->rows, A->columns, result))
      flag = INCORRECT_MATRIX;
    if (!flag) {
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return flag;
}