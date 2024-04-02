#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  double det = 0.0;

  error += s21_is_correct_matrix(A);

  if (!error) {
    if (A->rows == A->columns) {
      if (A->rows == 2) {
        det = A->matrix[0][0] * A->matrix[1][1] -
              A->matrix[0][1] * A->matrix[1][0];
      } else if (A->rows == 1) {
        det = A->matrix[0][0];
      } else {
        int N = A->rows;
        int sign = 1;
        for (int i = 0; i < N; i++) {
          matrix_t minor;
          s21_create_matrix(N - 1, N - 1, &minor);

          for (int j = 0; j < N - 1; j++) {
            for (int k = 0; k < N - 1; k++) {
              minor.matrix[j][k] = A->matrix[j + 1][(k >= i) ? k + 1 : k];
            }
          }
          double minor_det = 0.0;
          error = s21_determinant(&minor, &minor_det);
          if (error != OK) {
            s21_remove_matrix(&minor);
          }

          det += sign * A->matrix[0][i] * minor_det;
          sign = -sign;

          s21_remove_matrix(&minor);
        }
      }
    } else {
      error = COMPUTE_ERROR;
    }

    *result = det;
  }
  return error;
}