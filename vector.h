#include "rng.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef VECTOR_H

typedef struct {
  size_t dimension;
  float *data;
} Vector;

/**
 * Allocation / Destruction
 */

Vector vec_alloc(size_t dim);

void vec_free(Vector *v);

/**
 * Construction
 */

Vector vec_rand(size_t dim, float lo, float hi);

/**
 * Element access / retrieval
 */

float vec_get(const Vector v, size_t idx);

void vec_set(Vector v, size_t idx, float val);

/**
 * Vector operations
 */

void vec_scale(Vector v, float s);

void vec_add(Vector v1, const Vector v2);

void vec_sub(Vector v1, const Vector v2);

float vec_dot(const Vector v1, const Vector v2);

/**
 * Utility
 */

void vec_print(const Vector v);

#endif // !VECTOR_H
