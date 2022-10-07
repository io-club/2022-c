#include <stdio.h>

char get_char(int a, int b) { return a + b; }

int main(int argc, char const *argv[]) {

  char (*p)(int, int) = get_char;

  char c = p(24, 24);

  printf("%c\n", c);

  return 0;
}