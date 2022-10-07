#include <stdio.h>

int main(int count, char const *strings[]) {
  for (int i = 0; i < count; i++) {
    printf("%s\n", strings[i]);
  }
  return 0;
}
