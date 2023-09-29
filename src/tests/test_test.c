#include "s21_test.h"

START_TEST(test_test_1) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_scope(&main);
  button_clicked_dot(&main);
  button_clicked_1(&main);
  button_clicked_dot(&main);
  button_clicked_dot(&main);
  button_clicked_2(&main);
  button_clicked_plus(&main);
  button_clicked_9(&main);
  button_clicked_pow(&main);
  button_clicked_2(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 82.2, 1e-7);
  free(main.elements);
}
END_TEST

START_TEST(test_test_2) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_c(&main);
  button_clicked_c(&main);
  button_clicked_dot(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0, 1e-7);
  free(main.elements);
}

START_TEST(test_test_3) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_c(&main);
  button_clicked_c(&main);
  button_clicked_3(&main);
  button_clicked_4(&main);
  button_clicked_5(&main);
  button_clicked_6(&main);
  button_clicked_7(&main);
  button_clicked_8(&main);
  button_clicked_0(&main);
  button_clicked_dot(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 3456780, 1e-7);
  free(main.elements);
}

START_TEST(test_test_4) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_sin(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);
  button_clicked_c(&main);
  button_clicked_c(&main);
  button_clicked_c(&main);
  button_clicked_enter(&main);
  ck_assert_double_eq_tol(main.elements_size, 0, 1e-7);
  free(main.elements);
}

START_TEST(test_test_5) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));
  ck_assert_double_eq_tol(main.elements_size, 0, 1e-7);
  free(main.elements);
}

START_TEST(test_test_6) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_scope(&main);
  button_clicked_1(&main);
  button_clicked_plus(&main);
  button_clicked_3(&main);
  button_clicked_scope(&main);
  button_clicked_mult(&main);
  button_clicked_scope(&main);
  button_clicked_4(&main);
  button_clicked_pow(&main);
  button_clicked_2(&main);
  button_clicked_scope(&main);
  button_clicked_div(&main);
  button_clicked_2(&main);
  button_clicked_minus(&main);
  button_clicked_4(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 28, 1e-7);
  free(main.elements);
}
END_TEST

START_TEST(test_test_7) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_cos(&main);
  button_clicked_0(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_sin(&main);
  button_clicked_0(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 1, 1e-7);
  free(main.elements);
}
END_TEST

START_TEST(test_test_8) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_cos(&main);
  button_clicked_0(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);
  button_clicked_scope(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0.744237, 1e-5);
  free(main.elements);
}
END_TEST

START_TEST(test_test_9) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_log(&main);
  button_clicked_9(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_sqrt(&main);
  button_clicked_2(&main);
  button_clicked_5(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_tan(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_asin(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_acos(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_ln(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);
  button_clicked_plus(&main);
  button_clicked_atan(&main);
  button_clicked_1(&main);
  button_clicked_scope(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 9.86784, 1e-5);
  free(main.elements);
}
END_TEST

START_TEST(test_test_10) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_9(&main);
  button_clicked_mod(&main);
  button_clicked_2(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 1, 1e-5);
  free(main.elements);
}
END_TEST

START_TEST(test_test_11) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_x(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0, 1e-5);
  free(main.elements);
}
END_TEST

START_TEST(test_test_12) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_2(&main);
  button_clicked_x(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0, 1e-5);
  free(main.elements);
}
END_TEST

START_TEST(test_test_13) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_9(&main);
  button_clicked_mod(&main);
  button_clicked_2(&main);
  button_clicked_mult(&main);
  button_clicked_2(&main);
  button_clicked_mult(&main);
  button_clicked_2(&main);
  button_clicked_mult(&main);
  button_clicked_2(&main);
  button_clicked_ac(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0, 1e-5);
  ck_assert_int_eq(main.elements_size, 0);
  free(main.elements);
}
END_TEST

START_TEST(test_test_14) {
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  button_clicked_ac(&main);
  button_clicked_x(&main);

  button_clicked_enter(&main);

  ck_assert_double_eq_tol(main.result, 0, 1e-5);
  free(main.elements);
}
END_TEST

Suite *test_test() {
  Suite *suite = suite_create("test");
  TCase *tcase = tcase_create("test_tcase");

  tcase_add_test(tcase, test_test_1);
  tcase_add_test(tcase, test_test_2);
  tcase_add_test(tcase, test_test_3);
  tcase_add_test(tcase, test_test_4);
  tcase_add_test(tcase, test_test_5);
  tcase_add_test(tcase, test_test_6);
  tcase_add_test(tcase, test_test_7);
  tcase_add_test(tcase, test_test_8);
  tcase_add_test(tcase, test_test_9);
  tcase_add_test(tcase, test_test_10);
  tcase_add_test(tcase, test_test_11);
  tcase_add_test(tcase, test_test_12);
  tcase_add_test(tcase, test_test_13);
  tcase_add_test(tcase, test_test_14);

  suite_add_tcase(suite, tcase);
  return suite;
}
