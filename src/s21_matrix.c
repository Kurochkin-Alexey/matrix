#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int valid_checker = OK;
  if (rows < 1 || columns < 1) {
    valid_checker = INCORRECT_MATRIX;
  } else if (result == NULL) {
    valid_checker = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix == NULL || result->matrix[i] == NULL) {
        valid_checker = INCORRECT_MATRIX;
        s21_remove_matrix(result);
      }
    }
  }
  return valid_checker;
}