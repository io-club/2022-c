#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// 在 windows 有一个名为 getch 的函数，类似于 getchar
// 用户输入字符后，不用再按回车

// linux 上没有，需要手动实现
int getch(void) {
  int ch;
  struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}

int main(int argc, char const *argv[]) {
  char ch;
  for (;;) {
    ch = getch();
    printf("[%c]\n", ch);
  }
  return 0;
}