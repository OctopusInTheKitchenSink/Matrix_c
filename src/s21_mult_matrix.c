#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!A || !B) flag = INCORRECT_MATRIX;
  if (!flag && (A->columns < 1 || B->columns < 1 || A->rows < 1 || B->rows < 1))
    flag = INCORRECT_MATRIX;
  if (!flag && (A->columns != B->rows)) flag = CALCULATION_ERROR;
  if (!flag && s21_create_matrix(A->rows, B->columns, result))
    flag = INCORRECT_MATRIX;
  if (!flag)
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < B->rows; ++j)
        for (int k = 0; k < B->columns; ++k)
          result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
  return flag;
}