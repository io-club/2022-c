int main(int argc, char const *argv[]) {
  char a[] =
      "goodday"; // the compiler puts {'s','t','r','i','n','g', 0} onto STACK

  char *b = "helloworld"; // the compiler puts just the pointer onto STACK

  int c = 0b10; // 2
  c = 010;  // 8
  c = 10;   // 10
  c = 0x10; // 16
  return 0;
}
