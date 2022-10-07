#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str1[] = "aaa";
  char str2[] = "bbb";

  int res = strcmp(str1, str2);

  if (res == 0)
    printf("str1 等于 str2\n");
  else if (res > 0)
    printf("str1 大于 str2\n");
  else
    printf("str1 小于 str2\n");
  return 0;
}