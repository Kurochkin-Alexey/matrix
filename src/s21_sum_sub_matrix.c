#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int valid_checker = s21_valid_matrix_checker(A, B);
  if (valid_checker == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      valid_checker = s21_create_matrix(A->rows, A->columns, result);
      if (valid_checker == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            if (!isfinite(result->matrix[i][j])) {
              valid_checker = CALCULATION_ERROR;
            }
          }
          if (result->matrix[i] == NULL) {
            valid_checker = INCORRECT_MATRIX;
            s21_remove_matrix(result);
          }
        }
      }
    } else {
      valid_checker = CALCULATION_ERROR;
    }
  }
  return valid_checker;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int valid_checker = s21_valid_matrix_checker(A, B);
  if (valid_checker == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      valid_checker = s21_create_matrix(A->rows, A->columns, result);
      if (valid_checker == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            if (!isfinite(result->matrix[i][j])) {
              valid_checker = CALCULATION_ERROR;
            }
          }
          if (result->matrix[i] == NULL) {
            valid_checker = INCORRECT_MATRIX;
            s21_remove_matrix(result);
          }
        }
      }
    } else {
      valid_checker = CALCULATION_ERROR;
    }
  }
  return valid_checker;
}