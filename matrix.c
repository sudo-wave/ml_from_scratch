#include "matrix.h"
#include <stdio.h>

//---------------------------------------------------------------------//

Matrix mat_alloc(size_t row, size_t col) {
  assert(row > 0);
  assert(col > 0);

  Matrix m;
  m.rows = row;
  m.columns = col;
  m.dimension = row * col;
  m.data = malloc(row * col * sizeof(*m.data));
  return m;
}

void mat_free(Matrix *v);

//---------------------------------------------------------------------//

Matrix mat_rand(size_t rows, size_t cols, float lo, float hi) {
  assert(lo < hi);

  Matrix m = mat_alloc(rows, cols);
  for (size_t i = 0; i < m.rows; i++) {
    for (size_t j = 0; j < m.columns; j++) {
      m.data[i * m.columns + j] = get_rand() * (hi - lo) + lo;
    }
  }
  return m;
}

//---------------------------------------------------------------------//

float mat_get(const Matrix v, size_t idx);

void mat_set(Matrix v, size_t idx, float val);

//---------------------------------------------------------------------//

void mat_scale(Matrix v, float s);

void mat_add(Matrix v1, const Matrix v2);

void mat_sub(Matrix v1, const Matrix v2);

float mat_dot(const Matrix v1, const Matrix v2);

//---------------------------------------------------------------------//

void mat_print(const Matrix m) {
  assert(m.data != NULL);

  for (size_t i = 0; i < m.rows; i++) {
    for (size_t j = 0; j < m.columns; j++) {
      printf("%f ", m.data[i * m.columns + j]);
    }
    printf("\n");
  }
}
