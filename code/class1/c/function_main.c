#include <stdio.h>
int main(char *argv[]) {

  for (int i = 0; i < 5; i++) {
    printf("[%d] %s\n", i, argv[i]);
  }

  return 0;
}
