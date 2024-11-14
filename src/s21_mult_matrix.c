#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int valid_checker = OK;
  if (A->rows < 1 || A->columns < 1) {
    valid_checker = INCORRECT_MATRIX;
  } else if (!isfinite(number)) {
    return CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (result == NULL || result->matrix == NULL) {
      valid_checker = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
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
  }
  return valid_checker;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (result == NULL) {
    return INCORRECT_MATRIX;
  }
  int valid_checker = s21_valid_matrix_checker(A, B);
  if (valid_checker != OK) {
    return valid_checker;
  }
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }
  valid_checker = s21_create_matrix(A->rows, B->columns, result);
  if (valid_checker != OK) {
    return valid_checker;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        if (!isfinite(result->matrix[i][j])) {
          valid_checker = CALCULATION_ERROR;
        }
      }
    }
    if (result->matrix[i] == NULL) {
      valid_checker = INCORRECT_MATRIX;
      s21_remove_matrix(result);
    }
  }
  return valid_checker;
}