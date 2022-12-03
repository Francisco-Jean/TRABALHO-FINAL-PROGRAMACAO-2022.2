#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int dia;
  int mes;
  int ano;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};

struct passageiro {
int id;
char *nome;
char *endereco;
};
char cct1[50] , cct2[50], cct3[50] , cct4[50], cct5[50] , cct6[50] ;


/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
No *abb_cria_no(int chave, char conteudo) {
  if(chave<0){
    return NULL;
  }
  No *no = (No*) malloc(sizeof(No));
  strcpy(&no->conteudo,&conteudo);
  no->chave = chave;
  no->esq = NULL;
  no->dir = NULL;
  no->pai = NULL;
  return no;
}

/* Libera a memória de um nó e toda as suas sub-árvores. Retorna 1 se for
 * possivel fazer a liberação ou 0 caso o nó seja NULL. */
int abb_libera_no(No *no) {
  if (no == NULL) {
    return 0;
  }
  No *no_aux1= no->esq;
  No *no_aux2= no->dir;
  free(no);
  if (no_aux1 != NULL) {
    abb_libera_no(no_aux1);
  }
  if (no_aux2 != NULL){
    abb_libera_no(no_aux2);
  }
  return 1;
}

/* Retorna a chave do nó ou -1 caso o nó seja NULL.  */
int abb_chave_no(No *no) {
  if(no == NULL){
    return -1;
  }
  return no->chave;
}

/* Retorna o conteúdo do no ou '#' caso o nó seja NULL. */
char abb_conteudo_no(No *no) {
  if(no == NULL){
    return '#';
  }
  return no->conteudo;
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
No *abb_insere_no(No *raiz, No *no) {
  if (raiz == NULL && no == NULL) {
    return NULL;
  }
  No *aux2 = NULL;
  No *aux1 = raiz;

  while (aux1 != NULL) {
    aux2 = aux1;
    if (no->chave < aux1->chave) {
      aux1 = aux1->esq;
    }
    else if (no->chave > aux1->chave) {
      aux1 = aux1->dir;
    }
    else if (no->chave == aux2->chave){
      return NULL;
    }
  }
  if (raiz != NULL) {
    if (no->chave < aux2->chave) {
      aux2->esq = no;
    }
    else {
      aux2->dir = no;
    }

    no->pai = aux2;
  }
  else {
    raiz = no;
  }
  return raiz;
  //(no>=raiz)? raiz->esq=no:raiz->dir=no;
}

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
No *abb_busca_no(No *raiz, int chave) {
  No *no_aux = raiz;
  while(no_aux->chave != chave && no_aux != NULL){
    
    if (chave <= no_aux->chave){
      no_aux = no_aux->esq;
    }
    else{
      no_aux = no_aux->dir;
    }
  }
  return no_aux;
}


/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. */
No *abb_remove_no(No *raiz, int chave) {
  if(raiz == NULL){
    return NULL;
  }
  No *z = abb_busca_no(raiz,chave);
  if(z->esq == NULL){
    transplantar(raiz,z,z->dir);
    }
  else{
    No *x = sucessor(z);
    transplantar(raiz,z,z->dir);
    x->esq = z->esq;
    z->esq->pai = x;
    x->dir = z->dir;
    if(z->dir == NULL){
      z->dir->pai = x;
    }
    transplantar(raiz,z,x);
  }
  return raiz;
}

/* Retorna a altura da árvore ou -1 caso a raiz seja NULL. */
int abb_altura(No *raiz) {
  if(raiz == NULL){
    return -1;
  }
  int altura_esq = abb_altura(raiz->esq);
  int altura_dir = abb_altura(raiz->dir);

  if (altura_esq < altura_dir) {
    return altura_dir + 1;
  }
  else {
    return altura_esq + 1;
  }
}

/* Retorna o número de nós da árvore ou -1 caso araiz seja NULL. */
int abb_numero(No *raiz) {
  if(raiz == NULL){
    return -1;
  }
  int quant = 0;

  No *x = raiz;

  if (x->esq != NULL) {
    x = minimo(x->esq);
    quant += 1;
  }
  while (sucessor(x) != NULL) {
    x = sucessor(x);
    quant += 1;
  }
  return quant;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pré-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pre_ordem(No *no) {
  if(no == NULL){
    return "#";
  }
  if(no!=NULL){
    strcpy(cct1,(&(no->conteudo)));
    strcat(cct2,cct1);
    abb_pre_ordem(no->esq);
    abb_pre_ordem(no->dir);
  }   
  return cct2;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_ordem(No *no) {
  if (no == NULL) {
      return "#";
  }
  if(no!=NULL){ 
    abb_ordem(no->esq);
    strcpy(cct3,(&(no->conteudo)));
    strcat(cct4,cct3);
    abb_ordem(no->dir);
  }  
  return cct4;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pós-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pos_ordem(No *no) {
  if (no == NULL) {
      return "#";
  }
  if(no!=NULL){
    abb_pos_ordem(no->esq);
    abb_pos_ordem(no->dir);
    strcpy(cct5,(&(no->conteudo)));
    strcat(cct6,cct5);
  }  
  return cct6;
}

// FUNÇOES CRIADAS POR FORA

No *sucessor(No *no) {
  No *aux, *y;
  if (no->dir != NULL) {
    return minimo(no->dir);
  }
  y = no->pai;
  while (y != NULL && no == y->dir) {
    no = y;
    y = no->pai;
  }
  return y;
}

No *minimo (No *no) {
  while (no->esq != NULL) {
    no = no->esq;
  }
  return no;
}

char *pre_ordem(No *no, char *conc) {
  strcat(conc, &no->conteudo);
  pre_ordem(no->esq, conc);
  pre_ordem(no->dir, conc);
  return conc;
}

char *pos_ordem(No *no, char *conc) {
  pre_ordem(no->esq, conc);
  pre_ordem(no->dir, conc);
  strcat(conc, &no->conteudo);
  return conc;
}

void transplantar(No *raiz, No *no, No *novo_no){
  if (no->pai == NULL){
    raiz = novo_no;
  }
  else if (no == no->pai->esq){
    no->pai->esq = novo_no;
  }
  else{
    no->pai->dir = novo_no;
  }
  if(novo_no == NULL){
    novo_no->pai = no->pai;
  }
}