#include <stdio.h>
int main(int argc, char const *argv[]) { // scope 0

  int a = 0;

  {
    // scope 1
    int b = 0;
    printf("%d", a);

    { // scope 3
      int b = 1;
      printf("%d", b);
      printf("%d", a);
    }
  }

  { // scope 2
    printf("%d", a);
  }

  // int i;
  // for (i = 0; i < 10; i++) {
  //   //
  // }

  for (int i = 0; i < 10; i++) {
    //
  }

  // printf("%d", i);

  return 0;
}
