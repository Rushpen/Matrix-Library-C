#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define NONCORRECT_ERROR 1
#define COMPUTE_ERROR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;


//checking
int s21_check_rows_and_cols(int rows, int cols);
int s21_is_correct_matrix(matrix_t *A);
int s21_is_eq_sizes(matrix_t A, matrix_t B);

//Main operations
int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

void s21_create_minor(matrix_t *A, int exc_row, int exc_col, matrix_t *minor);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif