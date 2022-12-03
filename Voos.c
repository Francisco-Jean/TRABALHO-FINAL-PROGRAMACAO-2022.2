#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE VÔOS ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//

void printVoo(Voo *voo) {
  if (voo != NULL) {
    printf("Voo=%p\n", &voo);
    printf("\t.codigo=%d\n", voo->codigo);
    printf("\t.origem=%s\n", voo->origem);
    printf("\t.destino=%s\n", voo->destino);
  } else {
    printf("voo nulo\n");
  }
}

// Copia os campos do vôo já existente passado por referência para as seguintes variáveis//
void vooAcessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if (voo != NULL) {
    *codigo = voo->codigo;
    strcpy(origem,voo->origem);
    strcpy(destino,voo->destino);
  }
}

// Aloca espaço em memória para um vôo, para os campos desse vôo, e depois atribui os valores passados por referência para esse vôo //
Voo *criarVoo(int codigo, char *origem, char *destino) {
  Voo *novo_voo = (Voo *) malloc(sizeof(Voo));
  novo_voo->codigo = codigo;
  novo_voo->origem = (char *) malloc(30*sizeof(char));
  strcpy(novo_voo->origem, origem);
  novo_voo->destino = (char *) malloc(30*sizeof(char));
  strcpy(novo_voo->destino, destino);
  return novo_voo;
}


Voo *editarVoo(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL) {
    voo->codigo=codigo;
    strcpy(voo->origem,origem);
    strcpy(voo->destino,destino);
  }
  return voo;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DA LISTA DE VÔOS ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//

ListaVoo *listaVoo_cria() {
  ListaVoo *lista=(ListaVoo *)malloc(sizeof(ListaVoo));
  lista->primeiro=NULL;
  return lista;
}

int tamanho_lista(ListaVoo *lista){
  int cont = 0;
  struct no_voo *noAux=lista->primeiro;
  while(noAux != NULL) {
    cont++;
    noAux = noAux->proximo;
  }
  return cont;
}


int listaVoo_insere(ListaVoo *listaVoo, Voo *voo) { 
  struct no_voo *novoNo= (struct no_voo * )malloc(sizeof(struct no_voo));
  if (novoNo==NULL){
    return 1;
  }
  novoNo->voo= voo;
  novoNo->proximo= listaVoo->primeiro;
  listaVoo->primeiro=novoNo;
  return 0;
}

Voo *listaVoo_retira(ListaVoo *listaVoo, int codigo) { return 0; }

int vooIgual(Voo *voo1, Voo *voo2) { return 0; }

int listaVoo_libera(ListaVoo **listaVoo) { return 0; }

Voo *listaVoo_busca(ListaVoo *listaVoo, int codigo) {
  struct no_voo *noAux=listaVoo->primeiro;
  while (noAux != NULL) {
    if(noAux->voo->codigo == codigo) {
      return noAux->voo;
    }   
    noAux = noAux->proximo;
  }
  return NULL;
}

