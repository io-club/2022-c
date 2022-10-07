#include <stdio.h>

int main(int argc, char const *argv[]) {
  short a;
  goto a;
  a = 2;
a:
  printf("%d %d\n", a, sizeof(char));

  return 0;
}
