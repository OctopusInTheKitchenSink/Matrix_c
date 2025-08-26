#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (!A) flag = INCORRECT_MATRIX;
  if (!flag && (A->rows < 1 || A->columns < 1)) flag = INCORRECT_MATRIX;
  if (!flag && A->columns != A->rows) flag = CALCULATION_ERROR;
  if (!flag && A->rows == 1) *result = A->matrix[0][0];
  if (!flag && A->columns == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  if (!flag && A->columns == 3)
    *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
              A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
              A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2] -
              A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
              A->matrix[1][0] * A->matrix[0][1] * A->matrix[2][2] -
              A->matrix[1][2] * A->matrix[2][1] * A->matrix[0][0];
  if (!flag && A->columns > 3) {
    char param;
    *result = 0;
    int str = s21_zeros_counter(A, &param);
    for (int j = 0; j < A->rows; ++j) {
      int curr_row = ((param == 'c') ? j : str),
          curr_col = ((param == 'c') ? str : j);
      matrix_t minor_matrix;
      if ((A->matrix[curr_row][curr_col])) {
        flag = s21_minor(curr_row, curr_col, &minor_matrix, A);
        double minor_determinant;
        if (!flag &&
            !(flag = s21_determinant(&minor_matrix, &minor_determinant))) {
          minor_determinant *= A->matrix[curr_row][curr_col] * pow(-1, str + j);
          *result += minor_determinant;
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }
  return flag;
}