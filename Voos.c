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

// ↓↓ Copia os campos do vôo já existente para as seguintes variáveis passadas por parâmetro↓↓ //

void vooAcessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if (voo != NULL) {
    *codigo = voo->codigo;
    strcpy(origem,voo->origem);
    strcpy(destino,voo->destino);
  }
}

// ↓↓ Aloca espaço em memória para um vôo, para os campos desse vôo, e depois atribui os valores passados por referência para esse vôo ↓↓ //

Voo *criarVoo(int codigo, char *origem, char *destino) {
  if (verifica_params(codigo,origem,destino)==1){
    Voo *novo_voo = (Voo *) malloc(sizeof(Voo));
    novo_voo->codigo = codigo;
    novo_voo->origem = (char *) malloc(30*sizeof(char));
    strcpy(novo_voo->origem, origem);
    novo_voo->destino = (char *) malloc(30*sizeof(char));
    strcpy(novo_voo->destino, destino);
    return novo_voo;
    }
  return NULL; 
  }

// ↓↓ Libera a memória de um vôo previamente alocado ↓↓ //

void liberarVoo(Voo * voo){
  free(voo->origem);
  free(voo->destino);
  free(voo);
}

// ↓↓ Edita os campos de um vôo existente ↓↓ //

Voo *editarVoo(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL && verifica_params(codigo, origem,destino) == 1) {
    voo->codigo=codigo;
    strcpy(voo->origem,origem);
    strcpy(voo->destino,destino);
  }
  return voo;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴ FUNÇÕES DA LISTA DE VÔOS ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//

// ↓↓ Cria e aloca espaço na memória para iniciar uma lista de vôos ↓↓ //

ListaVoo *listaVoo_cria() {
  ListaVoo *lista=(ListaVoo *)malloc(sizeof(ListaVoo));
  lista->primeiro=NULL;
  return lista;
}

// ↓↓ Faz a contagem de vôos que estão atualmente na lista ↓↓ //

int tamanho_lista(ListaVoo *lista){
  int cont = 0;
  NoVoo *noAux=lista->primeiro;
  while(noAux != NULL) {
    cont++;
    noAux = noAux->proximo;
  }
  return cont;
}

// ↓↓ Aloca espaço na memória pra um nó e insere ele na lista ↓↓ //

int listaVoo_insere(ListaVoo *listaVoo, Voo *voo) { 
  NoVoo *novoNo= (NoVoo * )malloc(sizeof(NoVoo));
  if (novoNo==NULL){
    return 1;
  }
  novoNo->voo= voo;
  novoNo->proximo= listaVoo->primeiro;
  listaVoo->primeiro=novoNo;
  return 0;
}

// ↓↓ Retira e libera memória de um nó alocado na lista ↓↓ //

Voo *listaVoo_retira(ListaVoo *listaVoo, int codigo) {
  NoVoo *noAtual = listaVoo->primeiro;
  NoVoo *noAnt = NULL;
  while (noAtual != NULL) {
    if(noAtual->voo->codigo == codigo) {
      if(noAnt == NULL) {
        listaVoo->primeiro = noAtual->proximo;
      } else {
        noAnt->proximo=noAtual->proximo;
      }
      
      Voo *voo_removido=noAtual->voo;
      free(noAtual);
      return voo_removido;
    }
    noAnt=noAtual;
    noAtual= noAtual->proximo;
  }
  return NULL;
}

// ↓↓ Verifica se dois vôos são iguais.Retorna 1 em caso afirmativo ↓↓ //

int vooIgual(Voo *voo1, Voo *voo2) {
  //return voo1->codigo==voo2->codigo && strcomp(voo1->origem,voo2->origem) && strcomp(voo1->destino,voo2->destino); 
  int compara_org=strcmp(voo1->origem,voo2->origem);
  int compara_dest=strcmp(voo1->destino,voo2->destino);
  if ((voo1->codigo==voo2->codigo) && (compara_org==0) && (compara_dest==0)){
    return 1;
  }
  return 0;
}

// ↓↓ Libera a memória de uma lista de vôos e retorna 0 caso seja possível fazer a liberação ↓↓ //

int listaVoo_libera(ListaVoo **listaVoo) { 
  if(listaVoo != NULL) {
    if(*listaVoo != NULL) {
      NoVoo *noAtual=(*listaVoo)->primeiro;
      NoVoo*noProx=NULL;
      while(noAtual != NULL) {
        noProx = noAtual->proximo;
        liberarVoo(noAtual->voo);
        free(noAtual);
        noAtual= noProx;
      }
      free(*listaVoo);
      return 0;
    }
  }
  return 1;
}

// ↓↓ Realiza a busca por código em uma lista de vôos ↓↓ //

Voo *listaVoo_busca(ListaVoo *listaVoo, int codigo) {
  NoVoo *noAux=listaVoo->primeiro;
  while (noAux != NULL) {
    if(noAux->voo->codigo == codigo) {
      return noAux->voo;
    }   
    noAux = noAux->proximo;
  }
  return NULL;
}

// ↓↓ Função que verifica se os parâmetros passados por referência estão conforme o padrão ↓↓ //

int verifica_params(int codigo,char *origem, char *destino){
  if (codigo < 0 || origem == NULL || destino == NULL){
    return -1;
  }
  if (strlen(origem) > 30 || strlen(destino) > 30) {
    return -1;
  }
  return 1;
}
