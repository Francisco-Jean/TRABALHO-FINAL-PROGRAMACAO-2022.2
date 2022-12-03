#include <stdio.h>
#include "Voos.h"

int main(void) {
  Voo *voo = criarVoo(1, "FOR", "SAO");
  printVoo(voo);
  
  printf("Hello World\n");
  return 0;
}