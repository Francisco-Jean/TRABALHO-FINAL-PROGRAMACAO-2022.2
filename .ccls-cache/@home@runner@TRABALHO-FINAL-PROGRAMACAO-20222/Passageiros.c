#include "Passageiros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passageiro {
  int id;
  char nome[30];
  char endereco[30];
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

Lista *lista_cria() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->primeiro = NULL;
  return lista;
}

int lista_libera(Lista **lista) {
  if (lista == NULL) {
    return 0;
  }
  free(*lista);
  *lista = NULL;
  return 1;
}

int lista_insere(Lista *lista, Passageiro *passageiro) {
  if(lista == NULL || passageiro == NULL){
    return -1;
  }
  int id_base;
  char nome[30];
  char endereco[30];
  passageiroAcessa(passageiro, &id_base, nome, endereco);
  
  if (lista->primeiro == NULL){
    No *n_no = (No*) malloc(sizeof(No));
    n_no -> passageiro = passageiro;
    n_no->proximo = NULL;
    No **aux = &(lista->primeiro);
    *aux = n_no;
    return 1;
  }
  
  No *no_aux = lista->primeiro;
  No *no_aux_anterior = no_aux;
  while(no_aux != NULL){
    int id;
    passageiroAcessa(no_aux->passageiro, &id, nome, endereco);
    if (id_base == id){
      return 0;
    }
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  No *n_no = (No*) malloc(sizeof(No));
  n_no -> passageiro = passageiro;
  n_no->proximo = NULL;
  
  No **aux = &(no_aux_anterior->proximo);
  *aux = n_no;
  return 1;
}

// Função que será necessário editar para ser colocada em funcionamento

Passageiro *lista_retira(Lista *lista, int id) {
  if(lista == NULL || id < 0 || lista->primeiro->passageiro == NULL){ 
    return NULL;
  }
  if(lista->primeiro->passageiro->id == id){
    Passageiro *passageiro_retirado = lista->primeiro->passageiro;
    lista->primeiro = lista->primeiro->proximo;
    return passageiro_retirado;
  }
  No *passageiro_aux =lista->primeiro->proximo;
  No *passageiro_aux2 =lista->primeiro;
  while(passageiro_aux != NULL){
    if(passageiro_aux->passageiro->id == id){
      passageiro_aux2->proximo = passageiro_aux->proximo;
      return passageiro_aux->passageiro;
    }
    passageiro_aux2 = passageiro_aux;
    passageiro_aux = passageiro_aux->proximo;
  }
  return NULL;
}



Passageiro *lista_busca(Lista *lista, int id) {
  if (lista == NULL || lista->primeiro == 0|| id<0) {
    return NULL;
  }
  
  No *n_aux = lista->primeiro;
  int id_comparada;
  char nome[50];
  char endereco[50];
  
  do{
    passageiroAcessa(n_aux->passageiro, &id_comparada, nome,endereco);
    
    if(id_comparada == id){
      return n_aux->passageiro;
    }
    
    n_aux = n_aux->proximo;
    
  }while(n_aux != NULL);
  
  return NULL;
}

int lista_quantidade(Lista *lista) {
  if (lista == NULL) {
    return -1;
  }
  No * no_aux = lista->primeiro;
  No *no_aux_anterior = no_aux;
  int total = 0;
  while(no_aux != NULL){
    total ++;
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  return total;
}

int lista_vazia(Lista *lista) {
  if(lista->primeiro == NULL){
    return 1;
  }
  return 0;
}

//FUNÇÕES PARA PASSAGEIRO

int verifica_params1(int id,char *nome, char *endereco){
  if (id < 0 || nome == NULL || endereco == NULL){
    return -1;
  }
  if (strlen(nome) > 30 || strlen(endereco) > 30) {
    return -1;
  }
  return 1;
}

Passageiro *criarPassageiro(int id,char *nome, char *endereco){
  if(verifica_params1(id, nome, endereco) == -1){
    return NULL;
  }
  Passageiro *passageiro = (Passageiro*) malloc(sizeof(Passageiro));
  passageiro->id = id;
  strcpy(passageiro->nome, nome);
  strcpy(passageiro->endereco, endereco);
  return passageiro;
}

void removerPassageiro(Passageiro **passageiro){
  if(passageiro != NULL){
    free(*passageiro);
    *passageiro = NULL;
  }
}

void editarPassageiro(Passageiro *passageiro,int id, char *nome, char *endereco){
  if(passageiro != NULL && verifica_params1(id, nome, endereco) == 1){
    passageiro->id = id;
    strcpy(passageiro->nome,nome);
    strcpy(passageiro->endereco,endereco);
  }
}

void passageiroAcessa(Passageiro *passageiro, int *id, char *nome, char *endereco) {
  if (passageiro == NULL) {
    *id = -1;
    strcpy(nome, "NULL");
    strcpy(endereco, "NULL");
  } else {
    *id = passageiro->id;
    strcpy(nome, passageiro->nome);
    strcpy(endereco, passageiro->endereco);
  }
}

int passageiroIgual(Passageiro *passageiro1, Passageiro *passageiro2) {
  if(passageiro1 == NULL && passageiro2!= NULL){
    return 0;
  } else if(passageiro1 != NULL && passageiro2 == NULL){
    return 0;
  }  else if(passageiro1 == NULL && passageiro2== NULL){
    return -1;
  }
  if(passageiro1->id != passageiro2->id){
    return 0;
  }
  return 1;
}