#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *p;

  p = (char *) malloc(19);
  p = (char *) malloc(12);
  p = (char *) malloc(16);
  free(p);

  return 0;
}

