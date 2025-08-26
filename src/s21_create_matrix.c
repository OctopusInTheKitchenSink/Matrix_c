#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows < 1 || columns < 1) flag = INCORRECT_MATRIX;
  result->columns = columns;
  result->rows = rows;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) flag = INCORRECT_MATRIX;
  for (int i = 0; i < rows; ++i) {  // && !flag
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    /*if(result->matrix[i] == NULL){
            for(int k = 0; k < i; ++k) free(result->matrix[k]);
            free(result->matrix);
            flag = INCORRECT_MATRIX;
    }*/
  }
  return flag;
}