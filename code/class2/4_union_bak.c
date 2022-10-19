#include <stdio.h>

struct Point {
  int x;
  int y;
};

// 普通的 union, 无法判断究竟是那种变体
union Place {
  int OUTPUT;
  struct Point PATH;
  struct Point STONE;
  struct Point WALL;
};

// 使用 enum 和 union 组合，实现了一个功能更强大的枚举
struct FullFeaturePlace {
  enum { OUTPUT, PATH, STONE, WALL } type;
  union {
    int OUTPUT;
    struct Point PATH;
    struct Point STONE;
    struct Point WALL;
  } p;
};

int main(int argc, char const *argv[]) {
  union Place current_place;

  current_place = (union Place)1;

  current_place = (union Place)(struct Point){1, 2};
  // 现在的 place 到底是 PATH，还是 STONE。

  struct FullFeaturePlace p = {.type = PATH,
                               .p.PATH = {
                                   .x = 1,
                                   .y = 1,
                               }};

  switch (p.type) {
  case OUTPUT:
    printf("%s", "YOU WIN!");
    break;
  case PATH:
    printf("YOU ARE IN [%d, %d]", p.p.PATH.x, p.p.PATH.y);
    break;
  case STONE:
    printf("YOU ARE IN [%d, %d]", p.p.STONE.x, p.p.STONE.y);
    break;
  case WALL:
    printf("YOU ARE IN [%d, %d]", p.p.WALL.x, p.p.WALL.y);
    break;
  }

  return 0;
}