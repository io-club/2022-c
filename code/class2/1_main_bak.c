#include <stdio.h>
#include <stdlib.h>
int main() {
  char a[50][50] = {
      "######", //
      "#  #  ", //
      "# ## #", //
      "#  # #", //
      "##   #", //
      "######", //
  };
  int i, x, y, p, q;
  char ch;

  // 初始位置
  x = 1;
  y = 1;
  a[x][y] = 'O';

  system("clear");
  for (i = 0; i <= 5; i++)
    puts(a[i]);

  // 出口位置
  p = 1;
  q = 5;
  while (1) {
    // 如果是出口就退出
    if (x != p || y != q) {
      break;
    }

    // 获取用户输入
    ch = getchar();

    // 判断
    if (ch == 's') {
      if (a[x + 1][y] != '#') {
        a[x][y] = ' ';
        x++;
        a[x][y] = 'O';
      }
    }
    if (ch == 'w') {
      if (a[x - 1][y] != '#') {
        a[x][y] = ' ';
        x--;
        a[x][y] = 'O';
      }
    }
    if (ch == 'a') {
      if (a[x][y - 1] != '#') {
        a[x][y] = ' ';
        y--;
        a[x][y] = 'O';
      }
    }
    if (ch == 'd') {
      if (a[x][y + 1] != '#') {
        a[x][y] = ' ';
        y++;
        a[x][y] = 'O';
      }
    }
    system("clear");
    for (i = 0; i <= 5; i++)
      puts(a[i]);
  }
  printf("You win! \n");
  return 0;
}