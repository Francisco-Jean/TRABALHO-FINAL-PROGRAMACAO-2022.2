#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Voo *voo = criarVoo(1, "FOR", "SAO");
  printVoo(voo);
  int codigo = 0;
  char *origem = (char *)malloc(30 * sizeof(voo));
  char *destino = (char *)malloc(30 * sizeof(voo));
  vooAcessa(voo, &codigo, origem, destino);
  printf("valores acessados:\n");
  printf("\tcodigo=%d\n", codigo);
  printf("\torigem=%s\n", origem);
  printf("\tdestino=%s\n", destino);

  printf("Hello World\n");
  return 0;
}