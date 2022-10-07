#include <stdio.h>
void main() {
  char a1 = 255;    // 8     0000 0000
  short a2 = 1;     // 16
  int a3 = 0;       // 32
  long a4 = 0;      // 64
  long long a5 = 0; // 128
  // 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
  // 0000 0000 0000  0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
  // 0000 0000 0000 0000 0000 0000

  unsigned char b1 = 255;    // 8
  unsigned short b2 = 1;     // 16
  unsigned int b3 = 0;       // 32
  unsigned long b4 = 0;      // 64
  unsigned long long b5 = 0; // 128

  float c1 = 1.0;       // 32
  double c2 = 1.0;      // 64
  long double c3 = 1.0; // 128

  char c = 0; // ASCII
  char d = '\65';
  printf("%c\n", d);
}
