#include <stdio.h>

#include <stdio.h>
int main() { // scope 0
  int i = 0;
  { // scope 1
    int a = 0;
    // printf("%d", b);
    printf("%d", i);
  }

  { // scope 2
    int b = 0;
    // printf("%d", a);
    printf("%d", i);
  }

  // printf("%d", a);
  // printf("%d", b);

  return 0;
}