#include "../s21_matrix.h"

void s21_create_minor(matrix_t *A, int exc_row, int exc_col, matrix_t *minor) {
  int minor_i = 0;
  for (int row = 0; row < A->rows; row++) {
    if (row == exc_row) {
      continue;
    }

    int minor_j = 0;
    for (int col = 0; col < A->columns; col++) {
      if (col == exc_col) {
        continue;
      }

      minor->matrix[minor_i][minor_j] = A->matrix[row][col];
      minor_j++;
    }

    minor_i++;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;

  error += s21_is_correct_matrix(A);

  if (!error) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

          s21_create_minor(A, i, j, &minor);

          double minor_det = 0.0;
          error = s21_determinant(&minor, &minor_det);
          if (error != OK) {
            s21_remove_matrix(&minor);
            return error;
          }

          double complement = minor_det * ((i + j) % 2 == 0 ? 1 : -1);
          result->matrix[i][j] = complement;

          s21_remove_matrix(&minor);
        }
      }
    } else {
      error = COMPUTE_ERROR;
    }
  }

  return error;
}