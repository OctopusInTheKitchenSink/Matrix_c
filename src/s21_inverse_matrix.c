#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  double determinant;
  matrix_t tmp_matrix;
  if (!A) flag = INCORRECT_MATRIX;
  if (!flag && (A->columns < 1 || A->rows < 1)) flag = INCORRECT_MATRIX;
  if (!flag && A->columns != A->rows) flag = CALCULATION_ERROR;
  if (!flag && A->columns == 1) {
    flag = 5;
    if (!A->matrix[0][0])
      flag = CALCULATION_ERROR;
    else {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    }
  }
  if (!flag && !(flag = s21_determinant(A, &determinant)) && !determinant)
    flag = CALCULATION_ERROR;
  if (!flag && !(flag = s21_calc_complements(A, &tmp_matrix))) {
    flag = s21_transpose(&tmp_matrix, result);
    s21_remove_matrix(&tmp_matrix);
    for (int i = 0; i < A->rows && !flag; ++i)
      for (int j = 0; j < A->columns && !flag; ++j)
        result->matrix[i][j] /= determinant;
  }
  if (flag == 5) flag = 0;
  return flag;
}