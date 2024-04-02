#include "s21_calc_complements_test.h"

START_TEST(s21_calc_complements_test_1) {
  matrix_t A1;
  matrix_t result;
  matrix_t prec_result;

  int error = 0;
  error += s21_create_matrix(2, 2, &A1);
  error += s21_create_matrix(2, 2, &prec_result);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[1][0] = 3;
  A1.matrix[1][1] = 4;

  prec_result.matrix[0][0] = 4;
  prec_result.matrix[0][1] = -3;
  prec_result.matrix[1][0] = -2;
  prec_result.matrix[1][1] = 1;

  error += s21_calc_complements(&A1, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &prec_result), 1);
  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&A1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&prec_result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A1;
  matrix_t result;

  int error = 0;
  error += s21_create_matrix(2, 3, &A1);

  A1.matrix[0][0] = 1;
  A1.matrix[0][1] = 2;
  A1.matrix[1][0] = 3;
  A1.matrix[1][1] = 4;

  error += s21_calc_complements(&A1, &result);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A1);
}
END_TEST

Suite* s21_calc_complements_suite_create(void) {
  Suite* suite = suite_create("s21_calc_complements_suite");
  TCase* tcase_core = tcase_create("s21_calc_complements_tcase");
  tcase_add_test(tcase_core, s21_calc_complements_test_1);
  tcase_add_test(tcase_core, s21_calc_complements_test_2);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
