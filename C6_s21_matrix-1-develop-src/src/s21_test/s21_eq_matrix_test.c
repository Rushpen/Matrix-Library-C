#include "s21_eq_matrix_test.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A1;
  matrix_t A2;

  int error = 0;
  int result = 0;

  error += s21_create_matrix(2, 2, &A1);
  error += s21_create_matrix(2, 2, &A2);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[1][0] = 3;
  A1.matrix[1][1] = 4;

  A2.matrix[0][0] = 4;
  A2.matrix[0][1] = 3;
  A2.matrix[1][0] = 2;
  A2.matrix[1][1] = 1;

  result += s21_eq_matrix(&A1, &A2);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A1);
  s21_remove_matrix(&A2);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A1;
  matrix_t A2;

  int error = 0;
  int result = 0;

  error += s21_create_matrix(1, 1, &A1);
  error += s21_create_matrix(2, 2, &A2);

  A1.matrix[0][0] = 1;

  A2.matrix[0][0] = 4;
  A2.matrix[0][1] = 3;
  A2.matrix[1][0] = 2;
  A2.matrix[1][1] = 1;

  result += s21_eq_matrix(&A1, &A2);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A1);
  s21_remove_matrix(&A2);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A2;
  int error = 0;
  int result = 0;

  error += s21_create_matrix(2, 2, &A2);

  A2.matrix[0][0] = 4;
  A2.matrix[0][1] = 3;
  A2.matrix[1][0] = 2;
  A2.matrix[1][1] = 1;

  result += s21_eq_matrix(NULL, &A2);

  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A2);
}
END_TEST

Suite* s21_eq_matrix_suite_create(void) {
  Suite* suite = suite_create("s21_eq_matrix_suite");
  TCase* tcase_core = tcase_create("s21_eq_matrix_tcase");
  tcase_add_test(tcase_core, s21_eq_matrix_test_1);
  tcase_add_test(tcase_core, s21_eq_matrix_test_2);
  tcase_add_test(tcase_core, s21_eq_matrix_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}