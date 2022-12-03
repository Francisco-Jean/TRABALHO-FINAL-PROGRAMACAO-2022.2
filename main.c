#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Teste criarVoo\n");
  Voo *voo = criarVoo(1, "FOR", "SAO");
  printVoo(voo);
  
  printf("Teste editarVoo\n");
  editarVoo(voo,3,"BAHIA","NY");
  printVoo(voo);
  
  printf("Teste vooAcessa\n");
  int codigo = 0;
  char *origem = (char *)malloc(30 * sizeof(voo));
  char *destino = (char *)malloc(30 * sizeof(voo));
  vooAcessa(voo, &codigo, origem, destino);
  printf("valores acessados:\n");
  printf("\tcodigo=%d\n", codigo);
  printf("\torigem=%s\n", origem);
  printf("\tdestino=%s\n", destino);

  printf("teste listaVoo_cria\n");
  ListaVoo *listavoo=listaVoo_cria();
  printf("end lista=%p \n", listavoo);

  
  printf("Hello World\n");
  return 0;
}