#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = FAILURE;
  if (s21_valid_matrix_checker(A, B) == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res = SUCCESS;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
            res = FAILURE;
            break;
          }
        }
        if (res == FAILURE) break;
      }
    }
  }
  return res;
}