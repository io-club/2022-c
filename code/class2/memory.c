#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 1;
  int b = 2;
  int *c = &a;
  int *d = &b;
  printf("%p\n", &a);
  printf("%p\n", &b);
  printf("%p\n", &c);
  printf("%p\n", &d);
  return 0;
}