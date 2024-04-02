#include "s21_matrix.h"

int s21_check_rows_and_cols(int rows, int cols) {
  int error = OK;

  if (cols <= 0 || rows <= 0) {
    error = NONCORRECT_ERROR;
  }

  return error;
}

int s21_is_correct_matrix(matrix_t *A) {
  int result = 0;

  if (A == NULL) {
    result = 1;
  } else if (A->matrix == NULL) {
    result = 1;
  } else {
    result = s21_check_rows_and_cols(A->rows, A->columns);
  }

  return result;
}

int s21_is_eq_sizes(matrix_t A, matrix_t B) {
  int result = 1;

  if (A.rows != B.rows || A.columns != B.columns) {
    result = FAILURE;
  }
  return result;
}