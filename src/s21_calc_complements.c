#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL || A->rows < 1 ||
      A->columns < 1) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
    return OK;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor = s21_create_minor(i, j, A);
      if (minor.matrix == NULL) {
        return INCORRECT_MATRIX;
      }
      double det = 0;
      s21_determinant(&minor, &det);
      result->matrix[i][j] = pow(-1, i + j) * det;
      s21_remove_matrix(&minor);
    }
  }
  return OK;
}