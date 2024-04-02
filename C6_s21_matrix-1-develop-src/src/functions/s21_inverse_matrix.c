#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  double det = 0.0;

  error += s21_is_correct_matrix(A);

  if (!error) {
    if (A->rows == A->columns) {
      error = s21_determinant(A, &det);
      if (fabs(det) < 1e-7 || error != OK) {
        error = COMPUTE_ERROR;
      } else {
        matrix_t complements;
        s21_calc_complements(A, &complements);

        matrix_t transposed_complements;
        s21_transpose(&complements, &transposed_complements);

        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < transposed_complements.rows; i++) {
          for (int j = 0; j < transposed_complements.columns; j++) {
            result->matrix[i][j] = transposed_complements.matrix[i][j] / det;
          }
        }
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transposed_complements);
      }
    } else {
      error = COMPUTE_ERROR;
    }
  }

  return error;
}