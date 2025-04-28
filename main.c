#include "matrix.h"
#include <stdio.h>

int main() {
  printf("hello world\n");

  // Vector v = vec_rand(5, 0, 10);
  // vec_print(v);
  //
  // Vector u = vec_rand(5, 0, 100);
  // vec_print(u);
  //
  // vec_scale(v, 10);
  // vec_print(v);
  //
  // vec_add(v, u);
  // vec_print(v);
  //
  // vec_sub(v, u);
  // vec_print(v);
  //
  // float val = vec_dot(v, u);
  // printf("Dot Product between v and u: %f\n", val);

  Matrix m = mat_rand(2, 3, 0, 10);
  mat_print(m);
}
