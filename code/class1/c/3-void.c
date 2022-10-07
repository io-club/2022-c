#include <stdio.h>
void printSomething();

int main(int argc, char const *argv[]) {
  printSomething(1, 2);
  return 0;
}

void printSomething() {
  //
  printf("some text.\n");
}