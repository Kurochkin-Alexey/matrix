#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define EPSILON 1e-6

#define ck_assert_double_eq_tol(actual, expected, tol)                    \
  ck_assert_msg(                                                          \
      fabs((actual) - (expected)) < (tol),                                \
      "Assertion failed: %s == %s (within %f), actual: %f, expected: %f", \
      #actual, #expected, (tol), (actual), (expected))

#define ck_assert_double_eq(actual, expected)                           \
  ck_assert_msg(fabs((actual) - (expected)) < 1e-6,                     \
                "Assertion failed: %s == %s, actual: %f, expected: %f", \
                #actual, #expected, (actual), (expected))

#define ck_assert_ptr_null(X) ck_assert_ptr_eq((X), NULL)

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
matrix_t s21_create_minor(int excluded_row, int excluded_column,
                          matrix_t *matrix);
int s21_valid_matrix_checker(matrix_t *A, matrix_t *B);
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
void s21_init_matrix(double number, matrix_t *A);