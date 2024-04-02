#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  int rows = 0;
  int columns = 0;

  error += s21_is_correct_matrix(A);
  error += s21_is_correct_matrix(B);

  if (!error) {
    if (A->rows == B->columns) {
      rows = A->rows;
      columns = B->columns;

      error = s21_create_matrix(rows, columns, result);
      if (!error) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; ++k) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
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