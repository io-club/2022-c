#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum PointType { PATH, WALL, OUTPUT, USER } PointType;

typedef struct Map {
  int x;
  int y;

  PointType (*get_map_point_type)(struct Map *map, int x, int y);
  char **map;
} Map;

PointType get_map_point_type(Map *map, int x, int y) {
  char target = map->map[x][y];
  if ((x == 0 || x == map->x - 1 || y == 0 || y == map->y - 1) &&
      target == ' ') {
    return OUTPUT;
  } else if (target == '*' || target == '+' || target == '|' || target == '-') {
    return WALL;
  } else {
    return PATH;
  }
}

typedef struct User {
  int x;
  int y;

  PointType (*move)(struct User *, Map *, char);
} User;

PointType move(User *user, Map *map, char key) {
  printf("[KEY] %c\n", key);
  PointType next_point = PATH;
  switch (key) {
  case 'w':
    next_point = map->get_map_point_type(map, user->x - 1, user->y);
    if (next_point != WALL) {
      user->x -= 1;
    }
    break;
  case 'a':
    next_point = map->get_map_point_type(map, user->x, user->y - 1);
    if (next_point != WALL) {
      user->y -= 1;
    }
    break;
  case 's':
    next_point = map->get_map_point_type(map, user->x + 1, user->y);
    if (next_point != WALL) {
      user->x += 1;
    }
    break;
  case 'd':
    next_point = map->get_map_point_type(map, user->x, user->y + 1);
    if (next_point != WALL) {
      user->y += 1;
    }
    break;
  default:;
    printf("[WARN] 不支持的按键\n");
  }
  return next_point;
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
  Map map = {.x = x,
             .y = y,
             .map = heap_map,
             .get_map_point_type = get_map_point_type};
  return map;
}

int main(int argc, char const *argv[]) {
  // 🥹 🌵 🌲 🌴 🌳 🍀 ☘️ 🌿 🪵 🦔 🟫
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
  Map map = {.x = x,
             .y = y,
             .map = heap_map,
             .get_map_point_type = get_map_point_type};

  User user = {.x = 1, .y = 1, .move = move};
  while (true) {
    system("clear");
    print_map(&map, &user);
    char c;
    scanf(" %c", &c);
    if (user.move(&user, &map, c) == OUTPUT) {
      system("clear");
      print_map(&map, &user);
      printf("%s\n", "YOU WIN!");
      exit(EXIT_SUCCESS);
    }
  }

  free_map(&map);
  return 0;
}
