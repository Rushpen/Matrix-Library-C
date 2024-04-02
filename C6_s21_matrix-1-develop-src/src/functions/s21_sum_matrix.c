#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  int rows = 0;
  int columns = 0;

  error += s21_is_correct_matrix(A);
  error += s21_is_correct_matrix(B);

  if (!error) {
    if (s21_is_eq_sizes(*A, *B)) {
      rows = A->rows;
      columns = A->columns;

      error = s21_create_matrix(rows, columns, result);
      if (!error) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    } else {
      error = COMPUTE_ERROR;
    }
  } else {
    error = NONCORRECT_ERROR;
  }

  return error;
}