#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voo {
  int codigo;
  char origem[30];
  char destino[30];
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
  else{
    *codigo = -1;
    strcpy(origem,"NULL");
    strcpy(destino,"NULL");
  }
}

// ↓↓ Aloca espaço em memória para um vôo, para os campos desse vôo, e depois atribui os valores passados por referência para esse vôo ↓↓ //

Voo *criarVoo(int codigo, char *origem, char *destino) {
  if (verifica_params(codigo,origem,destino)==1){
    Voo *novo_voo = (Voo *) malloc(sizeof(Voo));
    novo_voo->codigo = codigo;
    strcpy(novo_voo->origem, origem);
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

void editarVoo(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL && verifica_params(codigo, origem,destino) == 1) {
    voo->codigo=codigo;
    strcpy(voo->origem,origem);
    strcpy(voo->destino,destino);
  }
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
  if(listaVoo == NULL || voo == NULL){
    return -1;
  }
  int codigo_base;
  char origem[30];
  char destino[30];
  vooAcessa(voo, &codigo_base, origem, destino);
  
  if (listaVoo->primeiro == NULL){
    NoVoo *n_no = (NoVoo*) malloc(sizeof(NoVoo));
    n_no -> voo = voo;
    n_no->proximo = NULL;
    NoVoo **aux = &(listaVoo->primeiro);
    *aux = n_no;
    return 1;
  }
  
  NoVoo *no_aux = listaVoo->primeiro;
  NoVoo *no_aux_anterior = no_aux;
  while(no_aux != NULL){
    int codigo;
    vooAcessa(no_aux->voo, &codigo, origem, destino);
    if (codigo_base == codigo){
      return 0;
    }
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  NoVoo *n_no = (NoVoo*) malloc(sizeof(NoVoo));
  n_no -> voo = voo;
  n_no->proximo = NULL;
  
  NoVoo **aux = &(no_aux_anterior->proximo);
  *aux = n_no;
  return 1;
}

// ↓↓ Retira e libera memória de um nó alocado na lista ↓↓ //

Voo *listaVoo_retira(ListaVoo *listaVoo, int codigo) {
  if(listaVoo == NULL || codigo < 0 || listaVoo->primeiro->voo == NULL){
    return NULL;
  }
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
  if (listaVoo == NULL) {
    return 0;
  }
  free(*listaVoo);
  *listaVoo = NULL;
  return 1;
}
// ↓↓ Realiza a busca por código em uma lista de vôos ↓↓ //

Voo *listaVoo_busca(ListaVoo *listaVoo, int codigo) {
  if (listaVoo == NULL || listaVoo->primeiro == 0 || codigo<0) {
    return NULL;
  }
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
  if (codigo <= 0 || origem == NULL || destino == NULL){
    return -1;
  }
  if (strlen(origem) > 30 || strlen(destino) > 30) {
    return -1;
  }
  return 1;
}

int verificaSequenciaVoos(Voo *voo1, Voo *voo2) {
  if(voo1 == NULL || voo2 == NULL) {
    return 0;
  }

  if(strcmp(voo1->destino, voo2->origem) == 0) {
    return 1;
  }

  return 0;
}
