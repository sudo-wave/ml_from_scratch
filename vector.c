#include "vector.h"

Vector vec_alloc(size_t dim) {
  assert(dim > 0);

  Vector v;
  v.dimension = dim;
  v.data = malloc(dim * sizeof(*v.data));
  return v;
}

void vec_free(Vector *v) {
  assert(v != NULL);

  v->dimension = 0;
  v->data = NULL;
  free(v);
}
//---------------------------------------------------------------------//

Vector vec_rand(size_t dim, float lo, float hi) {
  assert(lo < hi);
  Vector v = vec_alloc(dim);
  for (size_t i = 0; i < dim; i++) {
    v.data[i] = get_rand() * (hi - lo) + lo;
  }
  return v;
}

//---------------------------------------------------------------------//

void vec_scale(Vector v, float s) {
  assert(v.data != NULL);

  for (size_t i = 0; i < v.dimension; i++) {
    v.data[i] *= s;
  }
}

void vec_add(Vector v1, const Vector v2) {
  assert(v1.data != NULL);
  assert(v2.data != NULL);
  assert(v1.dimension == v2.dimension);

  for (size_t i = 0; i < v1.dimension; i++) {
    v1.data[i] += v2.data[i];
  }
}

void vec_sub(Vector v1, const Vector v2) {
  assert(v1.data != NULL);
  assert(v2.data != NULL);
  assert(v1.dimension == v2.dimension);

  for (size_t i = 0; i < v1.dimension; i++) {
    v1.data[i] -= v2.data[i];
  }
}

float vec_dot(const Vector v1, const Vector v2) {
  assert(v1.data != NULL);
  assert(v2.data != NULL);
  assert(v1.dimension == v2.dimension);

  float res = 0;
  for (size_t i = 0; i < v1.dimension; i++) {
    res += v1.data[i] * v2.data[i];
  }
  return res;
}

//---------------------------------------------------------------------//

float vec_get(const Vector v, size_t idx) {
  assert(idx < v.dimension);
  assert(v.data != NULL);

  return v.data[idx];
}

void vec_set(Vector v, size_t idx, float val) {
  assert(idx < v.dimension);
  assert(v.data != NULL);

  v.data[idx] = val;
}

//---------------------------------------------------------------------//

void vec_print(const Vector v) {
  assert(v.data != NULL);

  for (size_t i = 0; i < v.dimension; i++) {
    printf("%f ", v.data[i]);
  }
  printf("\n");
}
