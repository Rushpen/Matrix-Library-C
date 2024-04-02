#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  int rows = 0;
  int columns = 0;

  error += s21_is_correct_matrix(A);

  if (!error) {
    rows = A->columns;
    columns = A->rows;

    error = s21_create_matrix(rows, columns, result);
    if (!error) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }

  return error;
}