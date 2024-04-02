#include "s21_determinant_test.h"

START_TEST(s21_determinant_test_1) {
  matrix_t A1;
  double result = 0.0;

  int error = 0;
  error += s21_create_matrix(2, 2, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[1][0] = 3;
  A1.matrix[1][1] = 4;

  error += s21_determinant(&A1, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, -2.0, 1e-7);
  s21_remove_matrix(&A1);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A1;
  double result = 0.0;

  int error = 0;
  error += s21_create_matrix(3, 3, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[0][2] = 3;
  A1.matrix[1][0] = 4;
  A1.matrix[1][1] = 5;
  A1.matrix[1][2] = 6;
  A1.matrix[2][0] = 7;
  A1.matrix[2][1] = 8;
  A1.matrix[2][2] = 9;

  error += s21_determinant(&A1, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 0.0, 1e-7);
  s21_remove_matrix(&A1);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A1;
  double result = 0.0;

  int error = 0;
  error += s21_create_matrix(2, 3, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[0][2] = 3;
  A1.matrix[1][0] = 4;
  A1.matrix[1][1] = 5;
  A1.matrix[1][2] = 6;

  error += s21_determinant(&A1, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A1);
}
END_TEST

Suite* s21_determinant_suite_create(void) {
  Suite* suite = suite_create("s21_determinant_suite");
  TCase* tcase_core = tcase_create("s21_determinant_tcase");
  tcase_add_test(tcase_core, s21_determinant_test_1);
  tcase_add_test(tcase_core, s21_determinant_test_2);
  tcase_add_test(tcase_core, s21_determinant_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}