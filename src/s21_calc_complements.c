#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (!A) flag = INCORRECT_MATRIX;
  if (!flag && (A->columns < 1 || A->rows < 1)) flag = INCORRECT_MATRIX;
  if (!flag && A->columns != A->rows) flag = CALCULATION_ERROR;
  if (!flag && s21_create_matrix(A->rows, A->columns, result))
    flag = INCORRECT_MATRIX;
  if (!flag && A->columns == 1) {
    result->matrix[0][0] = A->matrix[0][0];
    flag = 5;
  }
  double tmp_det_result;
  if (!flag) {
    for (int i = 0; i < A->rows && !flag; ++i) {
      for (int j = 0; j < A->columns && !flag; ++j) {
        matrix_t minor_matrix;
        if (!(flag = s21_minor(i, j, &minor_matrix, A)) &&
            !(flag = s21_determinant(&minor_matrix, &tmp_det_result))) {
          result->matrix[i][j] =
              (!tmp_det_result ? tmp_det_result
                               : tmp_det_result * pow(-1, i + j));
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }
  if (flag == 5) flag = 0;
  return flag;
}