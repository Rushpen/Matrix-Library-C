#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (!A || !B) {
    result = FAILURE;
  } else if (!s21_is_eq_sizes(*A, *B)) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
        if (diff > 1e-7) {
          result = FAILURE;
        }
      }
    }
  }

  return result;
}