#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (!A || !B) flag = FAILURE;
  if (flag) {
    if (A->rows < 1 || A->columns < 1 || B->columns < 1 || B->rows < 1)
      flag = FAILURE;
    if (flag && (A->rows != B->rows || A->columns != B->columns))
      flag = FAILURE;
    for (int i = 0; i < A->rows && flag; ++i)
      for (int j = 0; j < A->columns && flag; ++j)
        if (trunc(A->matrix[i][j] * 10000000) !=
            trunc(B->matrix[i][j] * 10000000))
          flag = FAILURE;
  }
  return flag;
}