#include "s21_inverse_matrix_test.h"

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A1;
  matrix_t result;
  matrix_t prec_res;

  int error = 0;
  error += s21_create_matrix(2, 2, &A1);
  error += s21_create_matrix(2, 2, &prec_res);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[1][0] = 3;
  A1.matrix[1][1] = 4;

  prec_res.matrix[0][0] = -2;
  prec_res.matrix[0][1] = 1;
  prec_res.matrix[1][0] = 1.5;
  prec_res.matrix[1][1] = -0.5;

  error += s21_inverse_matrix(&A1, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &prec_res), 1);
  s21_remove_matrix(&A1);
  s21_remove_matrix(&prec_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A1;
  matrix_t result;

  int error = 0;
  error += s21_create_matrix(2, 2, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 4;
  A1.matrix[1][0] = 1;
  A1.matrix[1][1] = 4;

  error += s21_inverse_matrix(&A1, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A1;
  matrix_t result;

  int error = 0;
  error += s21_create_matrix(1, 2, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 4;

  error += s21_inverse_matrix(&A1, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A1);
}
END_TEST

Suite* s21_inverse_matrix_suite_create(void) {
  Suite* suite = suite_create("s21_inverse_matrix_suite");
  TCase* tcase_core = tcase_create("s21_inverse_matrix_tcase");
  tcase_add_test(tcase_core, s21_inverse_matrix_test_1);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_2);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}