#include <stdio.h>

enum State { INIT, START, END };

int main(int argc, char const *argv[]) {

  enum State state = INIT;
  for (;;) {
    switch (state) {
    case INIT:
      printf("init");
      state = START;
      break;
    case START:
      printf("start");
      state = END;
      break;
    default:
      exit(1);
      break;
    }
  }

  // for (;;) {
  //   switch (state) {
  //   case INIT:
  //     printf("init\n");
  //     state = START;
  //     break;
  //   case START:
  //     printf("start\n");
  //     state = END;
  //     break;
  //   case END:
  //     printf("end\n");
  //     state = UNKNOWN;
  //   case UNKNOWN:
  //     printf("发生错误\n");
  //     exit(1);
  //     break;
  //   default:
  //     printf("发生错误\n");
  //     exit(1);
  //   }
  // }
  return 0;
}
