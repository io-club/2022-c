// data
static int init_static = 1;
int initialized = 2;

// bss
int not_initialized;
long not_initialized_long;
static int not_init_static;
char name[] = "goodmorning";

int main() {
  // this is a comment
  int a = 1;
  int b = 2;
  int c = a + b;
  return 0;
}