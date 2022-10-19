#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // code here
  return 0;
}

struct Person_test {
  // 结构体的成员可以是任何基本类型

  int age;
  float height;
  float weight;
  char name[10];
};

int main_test(int argc, char const *argv[]) {
  struct Person_test jack;

  // 使用 '.' 去访问 Person 的各个成员
  jack.age = 1;
  jack.height = 175;
  jack.weight = 60;

  // 对数组的赋值需要使用 strcpy
  strcpy(jack.name, "Jack");

  return 0;
}