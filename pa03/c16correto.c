#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  int c;
  c=a/b;\
  return 0;
}

int calc(){
  int a;
  int b;
  a=13;
  b=0;
  if (b == 0){
    printf("e impossivel dividir por zero");
    return;
  }
  actual_calc(a, b);
  return 0;
}

int main(){
  calc();
  return 0;
}
