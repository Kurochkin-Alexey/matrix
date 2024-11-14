#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int valid_checker = OK;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) {
    s21_remove_matrix(result);
    return CALCULATION_ERROR;
  } else {
    matrix_t complements = {0}, complements_T = {0};
    valid_checker = s21_calc_complements(A, &complements);
    if (valid_checker == OK) {
      valid_checker = s21_transpose(&complements, &complements_T);
      if (valid_checker == OK) {
        for (int x = 0; x < A->rows; x++) {
          for (int y = 0; y < A->rows; y++) {
            result->matrix[x][y] = complements_T.matrix[x][y] / det;
          }
        }
      }
      s21_remove_matrix(&complements);
      s21_remove_matrix(&complements_T);
    } else {
      s21_remove_matrix(result);
    }
  }
  return valid_checker;
}