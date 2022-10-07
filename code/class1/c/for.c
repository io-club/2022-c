#include <stdio.h>

int main(int arguments_number, char *arguments[]) {
  // arguments = {"./a.out", "afadad", "adwfawf"}
  printf("%d \n", arguments_number);
  printf("你的文件是 %s\n", arguments[0]);
  printf("第一个参数是 %s\n", arguments[1]);
  printf("第二个参数是 %s\n", arguments[2]);
  for (int i = 0; i < 5; i = i + 1) {
    printf("%d\n", i);
  }

  // sum += i * j;
  // sum = sum + i * j;

  return 0;
}
