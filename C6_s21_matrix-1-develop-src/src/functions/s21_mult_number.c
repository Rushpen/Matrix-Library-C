#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  int rows = 0;
  int columns = 0;

  error += s21_is_correct_matrix(A);

  if (!error) {
    rows = A->rows;
    columns = A->columns;

    error = s21_create_matrix(rows, columns, result);
    if (!error) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }

  return error;
}