#include "s21_matrix.h"

int s21_valid_matrix_checker(matrix_t *A, matrix_t *B) {
  int status = 0;
  if (A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
    status = INCORRECT_MATRIX;
  } else if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL) {
    status = INCORRECT_MATRIX;
  }
  return status;
}

matrix_t s21_create_minor(int excluded_row, int excluded_column,
                          matrix_t *matrix) {
  matrix_t minor;
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, &minor);
  for (int i = 0, m_i = 0; i < matrix->rows; i++) {
    if (i != excluded_row) {
      for (int j = 0, m_j = 0; j < matrix->columns; j++) {
        if (j != excluded_column) {
          minor.matrix[m_i][m_j] = matrix->matrix[i][j];
          m_j++;
        }
      }
      m_i++;
    }
  }
  return minor;
}
