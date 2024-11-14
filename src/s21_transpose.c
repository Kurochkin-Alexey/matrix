#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int valid_checker = OK;
  if (A->rows < 1 || A->columns < 1) {
    valid_checker = INCORRECT_MATRIX;
  } else {
    if (result == NULL) {
      valid_checker = INCORRECT_MATRIX;
    } else {
      s21_create_matrix(A->columns, A->rows, result);
      if (result->matrix == NULL) {
        valid_checker = INCORRECT_MATRIX;
      } else {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[j][i] = A->matrix[i][j];
          }
        }
      }
    }
  }
  return valid_checker;
}
