#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Teste criarVoo\n");
  Voo *voo1 = criarVoo(1, "FOR", "SAO");
  printVoo(voo1);
  
  printf("Teste editarVoo\n");
  editarVoo(voo1,3,"BAHIA","NY");
  printVoo(voo1);
  
  printf("Teste vooAcessa\n");
  int codigo = 0;
  char *origem = (char *)malloc(30 * sizeof(char));
  char *destino = (char *)malloc(30 * sizeof(char));
  vooAcessa(voo1, &codigo, origem, destino);
  printf("valores acessados:\n");
  printf("\tcodigo=%d\n", codigo);
  printf("\torigem=%s\n", origem);
  printf("\tdestino=%s\n", destino);
  
  printf("teste listaVoo_cria\n");
  ListaVoo *listaVoo=listaVoo_cria();
  printf("end lista=%p \n", listaVoo);
  Voo *voo2=criarVoo(5,"MIA","GRU");
  listaVoo_insere(listaVoo,voo1);
  listaVoo_insere(listaVoo,voo2);
  printf("end lista=%p \n", listaVoo);
  printf("tamanho da lista:%d\n",tamanho_lista(listaVoo));


  
  printf("teste busca sucesso\n");
  Voo *resultado=listaVoo_busca(listaVoo,5);
  printVoo(resultado);

  printf("teste busca falha\n");
  resultado=listaVoo_busca(listaVoo,6);
  printVoo(resultado);

  Voo *voo3=criarVoo(5,"MIA","GRU");
  printf("teste voos iguais\n");
  if (vooIgual(voo3,voo2)==1){
    printf("voos iguais\n");
  }
  else{
    printf("voos dif\n");
  }

  printf("teste voos diferentes\n");
  if (vooIgual(voo1,voo2)==1){
    printf("voos iguais\n");
  }
  else{
    printf("voos dif\n");
  }

  printf("Hello World\n");
  return 0;
}