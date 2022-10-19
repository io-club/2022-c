#include <stdio.h>

#define LIGHT 3
#define DARK 1

const int LISHT = 1;

enum Week {
  Monday = 0,
  Tuesday = 1,
  Wednesday = 2,
  Thursday,
  Friday,
};

int main(int argc, char const *argv[]) {
  int state;
  state = LIGHT;
  state = DARK;

  printf("%d\n", LIGHT);
  return 0;
}