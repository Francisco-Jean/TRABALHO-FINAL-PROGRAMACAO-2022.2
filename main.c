#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include "AgendaReservas.h"
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
  
  printf("teste remoção\n");
  printf("tamanho da lista antes=%d\n",tamanho_lista(listaVoo));
  Voo *voo_removido = listaVoo_retira(listaVoo,5);
  printf("tamanho da lista depois=%d\n",tamanho_lista(listaVoo));
  printVoo(voo_removido); 
  
  printf("teste free\n");
  int resultadoFree = listaVoo_libera(&listaVoo);
  printf("free lista voo=%d\n", resultadoFree);

  free(origem);
  free(destino);
  liberarVoo(voo2);
  liberarVoo(voo3);

  printf("teste de datas\n");
  Data *data1= data_cria(2,4,2000);
  printf("data1\n");
  print_data(data1);
  Data *data2= data_cria(3,4,2000);
  printf("data2\n");
  print_data(data2);
  Data *data3= data_cria(2,4,2000);
  printf("data3\n");
  print_data(data3);

  printf("teste data1 < data2 (deve retornar -1)\n");
  printf("retorno: %d\n",data_compara(data1,data2));

  printf("teste data1 > data2 (deve retornar 1)\n");
  printf("retorno: %d\n",data_compara(data2,data1));

  printf("teste data1 == data2 (deve retornar 0)\n");
  printf("retorno: %d\n",data_compara(data1,data3));
  
  printf("Hello World\n");
  return 0;
}
