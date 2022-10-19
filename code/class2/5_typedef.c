#include <stdlib.h>
#include <unistd.h>

int add(int a, int b) { return a + b; }

typedef int (*add_fn)(int, int);

typedef int F(int, int);

int main() {
  int define_a_fn_type(int, int);

  int (*fn)(int, int) = add;

  add_fn f = add;

  int c = f(1, 2);

  int a = 1;
  int b = 2;
  int *arr[] = {&a, &b};

  int (*arr_fn[])(int, int) = {add};

  int (*(*arr_fn_p)[])(int, int) = &arr_fn;

  add_fn first_fn = arr_fn[0];

  void *p = arr_fn_p;
  c = (*((int (*(*)[])(int, int))p))[0](1, 2);

  return 0;
}