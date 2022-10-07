#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map {
  int x;
  int y;

  bool (*check)(struct Map *map, int x, int y);
  char **map;
} Map;

bool check_path(Map *map, int x, int y) {
  char target = map->map[x][y];
  if ((x == 0 || x == map->x - 1 || y == 0 || y == map->y - 1) &&
      target == ' ') {
    exit(EXIT_SUCCESS);
  } else if (target == '*' || target == '+' || target == '|' || target == '-') {
    return false;
  } else {
    return true;
  }
}

typedef struct User {
  int x;
  int y;

  bool (*move)(struct User *, Map *, char);
} User;

bool move(User *user, Map *map, char key) {
  printf("[KEY] %c\n", key);
  switch (key) {
  case 'w':
    if (map->check(map, user->x - 1, user->y)) {
      user->x -= 1;
    }
    break;
  case 'a':
    if (map->check(map, user->x, user->y - 1)) {
      user->y -= 1;
    }
    break;
  case 's':
    if (map->check(map, user->x + 1, user->y)) {
      user->x += 1;
    }
    break;
  case 'd':
    if (map->check(map, user->x, user->y + 1)) {
      user->y += 1;
    }
    break;
  default:;
    printf("[WARN] 不支持的按键\n");
    return false;
  }
  return true;
}

void print_map(Map *map, User *user) {
  char current = map->map[user->x][user->y];
  map->map[user->x][user->y] = '@';
  for (int i = 0; i < map->x; i++) {
    for (int j = 0; j < map->y; j++) {
      printf("%c", map->map[i][j]);
    }
    printf("\n");
  }
  map->map[user->x][user->y] = current;
}

void free_map(Map *map) {
  for (int i = 0; i < map->x; i++) {
    free(map->map[i]);
  }
  free(map);
}

Map init_map(char map_stack[100][100], int x, int y) {
  char **heap_map = malloc(sizeof(char *) * x);
  for (int i = 0; i < x; i++) {
    heap_map[i] = malloc(sizeof(char *) * y);
    heap_map[i] = map_stack[i];
  }
  Map map = {.x = x, .y = y, .map = heap_map, .check = check_path};
  return map;
}

int main(int argc, char const *argv[]) {
  char map_stack[6][6] = {
      "+----+", // 0
      "|  *  ", // 1 出口
      "| ** +", //
      "|  * |", //
      "|*   |", //
      "+----+", // 5
  };
  char y = sizeof(map_stack[0]);
  char x = sizeof(map_stack) / y;
  char **heap_map = malloc(sizeof(char *) * x);
  for (int i = 0; i < x; i++) {
    heap_map[i] = malloc(sizeof(char *) * y);
    heap_map[i] = map_stack[i];
  }

  Map map = {.x = x, .y = y, .map = heap_map, .check = check_path};

  User user = {.x = 1, .y = 1, .move = move};
  while (true) {
    print_map(&map, &user);
    // char c;
    // scanf(" %c", &c);
    char c = getchar();
    user.move(&user, &map, c);
  }

  free_map(&map);
  return 0;
}
