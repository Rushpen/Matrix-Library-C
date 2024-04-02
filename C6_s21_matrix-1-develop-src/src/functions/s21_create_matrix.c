#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (result == NULL) {
    error = NONCORRECT_ERROR;
  } else {
    error = s21_check_rows_and_cols(rows, columns);
    if (!error) {
      result->rows = rows;
      result->columns = columns;
      result->matrix = calloc(rows, sizeof(double *));

      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    }
  }

  return error;
}