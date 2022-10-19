#include <stdio.h>

int add(int a, int b) {
  // printf("[%p] a\n", &a);
  // printf("[%p] b\n", &b);
  return a + b;
}

int main(int argc, char const *argv[]) {
  int a = 1;
  int b = 2;
  // printf("[%p] a\n", &a);
  // printf("[%p] b\n", &b);
  int c = add(a, b);
  return 0;
}