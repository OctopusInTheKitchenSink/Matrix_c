#include "s21_matrix.h"

int s21_minor(int row, int col, matrix_t *A, matrix_t *inic_matrix) {
  int flag = OK;
  if (s21_create_matrix(inic_matrix->rows - 1, inic_matrix->columns - 1, A))
    flag = INCORRECT_MATRIX;
  if (!flag) {
    int tmp_i = 0, tmp_j = 0;
    for (int i = 0; i < inic_matrix->rows; ++i) {
      tmp_j = 0;
      for (int j = 0; j < inic_matrix->columns; ++j) {
        if (i != row && j != col)
          A->matrix[tmp_i][tmp_j++] = inic_matrix->matrix[i][j];
      }
      if (i != row) tmp_i++;
    }
  }
  return flag;
}

int s21_zeros_counter(matrix_t *A, char *param) {
  int zero_counter, max_zero_row = 0, max_zero_col = 0, row = 0, col = 0;
  for (int i = 0; i < A->rows; ++i) {
    zero_counter = 0;
    for (int j = 0; j < A->columns; ++j)
      if (!(A->matrix[i][j])) zero_counter++;
    if (zero_counter > max_zero_row) {
      max_zero_row = zero_counter;
      row = i;
    }
  }
  for (int i = 0; i < A->columns; ++i) {
    zero_counter = 0;
    for (int j = 0; j < A->columns; ++j) {
      if (!(A->matrix[j][i])) zero_counter++;
    }
    if (zero_counter > max_zero_col) {
      max_zero_col = zero_counter;
      col = i;
    }
  }
  *param = ((max_zero_col > max_zero_row) ? 'c' : 'r');
  return ((max_zero_col > max_zero_row) ? col : row);
}