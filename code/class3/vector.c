#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
  int cap;
  int len;
  char *inner;
  void (*push)(struct Vector *, char elem);
} Vector;

void vec_push(Vector *vec, char elem) {
  if (vec->len == vec->cap) {
    vec->inner = realloc(vec->inner, vec->cap * 2);
    vec->cap *= 2;
  }
  vec->inner[vec->len] = elem;
  vec->len += 1;
}

Vector *vec_init(int cap) {
  Vector *vec = malloc(sizeof(Vector));
  *vec = (Vector){.len = 0,
                  .cap = cap,
                  .push = vec_push,
                  .inner = malloc(sizeof(char) * cap)};
  return vec;
}

void vec_remove(Vector *vec, size_t index) {

}

int main(int argc, char const *argv[]) {
  Vector *vec = vec_init(5);
  for (int i = 0; i < 12; i++) {
    vec->push(vec, 'c');
  }
  vec->push(vec, '\0');
  printf("%s \n", vec->inner);

  return 0;
}