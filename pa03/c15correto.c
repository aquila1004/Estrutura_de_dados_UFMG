#include <stdio.h>
#include <stdlib.h>

int inc(int a) {
  return a+1;
}

int main(int argc, char** argv) {
  int a = 1;//erro aqui
  for(int i=1; i < 5; i++) {
    a = inc(a);
    printf("%d\n", a);
  }

  return argc;
}