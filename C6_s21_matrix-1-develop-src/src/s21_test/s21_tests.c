#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_calc_complements_test.h"
#include "s21_create_matrix_test.h"
#include "s21_determinant_test.h"
#include "s21_eq_matrix_test.h"
#include "s21_inverse_matrix_test.h"
#include "s21_mult_matrix_test.h"
#include "s21_mult_number_test.h"
#include "s21_sub_matrix_test.h"
#include "s21_sum_matrix_test.h"

int main() {
  int failed_count = 0;
  Suite* suite1 = s21_calc_complements_suite_create();
  Suite* suite2 = s21_create_matrix_suite_create();
  Suite* suite3 = s21_determinant_suite_create();
  Suite* suite4 = s21_eq_matrix_suite_create();
  Suite* suite5 = s21_inverse_matrix_suite_create();
  Suite* suite6 = s21_mult_matrix_suite_create();
  Suite* suite7 = s21_mult_number_suite_create();
  Suite* suite9 = s21_sub_matrix_suite_create();
  Suite* suite10 = s21_sum_matrix_suite_create();

  SRunner* suite_runner1 = srunner_create(suite1);
  SRunner* suite_runner2 = srunner_create(suite2);
  SRunner* suite_runner3 = srunner_create(suite3);
  SRunner* suite_runner4 = srunner_create(suite4);
  SRunner* suite_runner5 = srunner_create(suite5);
  SRunner* suite_runner6 = srunner_create(suite6);
  SRunner* suite_runner7 = srunner_create(suite7);
  SRunner* suite_runner9 = srunner_create(suite9);
  SRunner* suite_runner10 = srunner_create(suite10);

  srunner_run_all(suite_runner1, CK_NORMAL);
  srunner_run_all(suite_runner2, CK_NORMAL);
  srunner_run_all(suite_runner3, CK_NORMAL);
  srunner_run_all(suite_runner4, CK_NORMAL);
  srunner_run_all(suite_runner5, CK_NORMAL);
  srunner_run_all(suite_runner6, CK_NORMAL);
  srunner_run_all(suite_runner7, CK_NORMAL);
  srunner_run_all(suite_runner9, CK_NORMAL);
  srunner_run_all(suite_runner10, CK_NORMAL);

  failed_count += srunner_ntests_failed(suite_runner1);
  failed_count += srunner_ntests_failed(suite_runner2);
  failed_count += srunner_ntests_failed(suite_runner3);
  failed_count += srunner_ntests_failed(suite_runner4);
  failed_count += srunner_ntests_failed(suite_runner5);
  failed_count += srunner_ntests_failed(suite_runner6);
  failed_count += srunner_ntests_failed(suite_runner7);
  failed_count += srunner_ntests_failed(suite_runner9);
  failed_count += srunner_ntests_failed(suite_runner10);

  srunner_free(suite_runner1);
  srunner_free(suite_runner2);
  srunner_free(suite_runner3);
  srunner_free(suite_runner4);
  srunner_free(suite_runner5);
  srunner_free(suite_runner6);
  srunner_free(suite_runner7);
  srunner_free(suite_runner9);
  srunner_free(suite_runner10);

  printf("Fail = %d\n", failed_count);

  return 0;
}
