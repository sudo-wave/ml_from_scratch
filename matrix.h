#include "vector.h"

#ifndef MATRIX_H

typedef struct {
  size_t rows;
  size_t columns;
  size_t dimension;
  float *data;
} Matrix;

/**
 * Allocation / Destruction
 */

Matrix mat_alloc(size_t row, size_t col);

void mat_free(Matrix *v);

/**
 * Construction
 */

Matrix mat_rand(size_t rows, size_t cols, float lo, float hi);

/**
 * Element access / retrieval
 */

float mat_get(const Matrix v, size_t idx);

void mat_set(Matrix v, size_t idx, float val);

/**
 * Matrix operations
 */

void mat_scale(Matrix v, float s);

void mat_add(Matrix v1, const Matrix v2);

void mat_sub(Matrix v1, const Matrix v2);

float mat_dot(const Matrix v1, const Matrix v2);

/**
 * Utility
 */

void mat_print(const Matrix h);

#endif // !MATRIX_H
