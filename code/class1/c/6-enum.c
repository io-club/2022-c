#include <stdio.h>

#define LIGHT 1
#define DARK 1

enum Week {
  Monday = 0,
  Tuesday = 1,
  Wednesday = 2,
  Thursday,
  Friday,
};

int main(int argc, char const *argv[]) {
  printf("%d\n", LIGHT);
  return 0;
}