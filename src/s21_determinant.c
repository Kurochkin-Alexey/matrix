#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  int valid_checker = OK;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else if (A->rows > 2) {
    int sign = 1;
    *result = 0;
    for (int i = 0; i < A->columns && valid_checker == OK; i++) {
      matrix_t minor = s21_create_minor(0, i, A);
      if (minor.matrix == NULL) {
        valid_checker = INCORRECT_MATRIX;
      } else {
        double minor_det = 0;
        valid_checker = s21_determinant(&minor, &minor_det);
        if (!valid_checker) {
          *result += sign * A->matrix[0][i] * minor_det;
          sign = -sign;
        }
        s21_remove_matrix(&minor);
      }
    }
  }
  return valid_checker;
}