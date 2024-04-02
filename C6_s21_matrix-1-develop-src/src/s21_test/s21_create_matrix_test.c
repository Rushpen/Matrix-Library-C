#include "s21_create_matrix_test.h"

START_TEST(s21_create_matrix_test_1) {
  matrix_t A1;

  int error = 0;
  error += s21_create_matrix(2, 2, &A1);

  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&A1);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t A1;

  int error = 0;
  error += s21_create_matrix(0, 2, &A1);

  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  int error = 0;
  error += s21_create_matrix(0, 2, NULL);

  ck_assert_int_eq(error, 1);
}
END_TEST

Suite* s21_create_matrix_suite_create(void) {
  Suite* suite = suite_create("s21_create_matrix_suite");
  TCase* tcase_core = tcase_create("s21_create_matrix_tcase");
  tcase_add_test(tcase_core, s21_create_matrix_test_1);
  tcase_add_test(tcase_core, s21_create_matrix_test_2);
  tcase_add_test(tcase_core, s21_create_matrix_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}