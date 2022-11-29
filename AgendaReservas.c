#include "AgendaReservas.h"
#include <stdio.h>
#include <stdlib.h>

//arvore binaria de busca
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
  Agenda *pai;
  Agenda *raiz;
};

struct passageiro {
int id;
char *nome;
char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

/* Aloca e retorna uma Agenda com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
Agenda *abb_cria_agenda(Reserva *reserva) {
  if(reserva->codigo<0){
    return NULL;
  }
  
  Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));
  agenda->reserva = reserva;
  agenda->esq = NULL;
  agenda->dir = NULL;
  agenda->pai = NULL;
  return agenda;
}

/* Retorna o codigo da reserva ou '#' caso o nó seja NULL. */
int abb_codigo_reserva(Reserva *reserva) {
  if(reserva == NULL){
    return '#';
  }
  return reserva->codigo;
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
Agenda *abb_insere_agenda(Agenda *raiz, Agenda *agenda) {
  if (raiz == NULL && agenda == NULL) {
    return NULL;
  }
  Agenda *aux2 = NULL;
  Agenda *aux1 = raiz;

  while (aux1 != NULL) {
    aux2 = aux1;
    if (agenda->reserva->data_viagem < aux1->reserva->data_viagem) {
      aux1 = aux1->esq;
    }
    else if (agenda->reserva->data_viagem > aux1->reserva->data_viagem) {
      aux1 = aux1->dir;
    }
    else if (agenda->reserva->data_viagem == aux2->reserva->data_viagem){
      return NULL;
    }
  }
  if (raiz != NULL) {
    if (agenda->reserva->data_viagem < aux2->reserva->data_viagem) {
      aux2->esq = agenda;
    }
    else {
      aux2->dir = agenda;
    }
    agenda->pai = aux2;
  }
  else {
    raiz = agenda;
  }
  return raiz;
}

/* Procura o reserva pelo id e codigo. Retorna a reserva caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
Reserva *abb_busca_reserva(Agenda *raiz,int id, int codigo, Data *data_viagem) {
  if(id<0 || codigo<0 || data_viagem == NULL){
    return NULL;
  }
  if(id != 0 && codigo != 0 && data_viagem == NULL){
    Reserva *reserva = em_ordem(raiz,id,codigo);
    return reserva;
  }
  else if(id != 0 && codigo == 0 && data_viagem != NULL){
    Agenda *agenda_aux = raiz;
    while(agenda_aux->reserva->data_viagem != data_viagem && agenda_aux->reserva->passageiro->id != id){
      if (agenda_aux->reserva->data_viagem <= data_viagem){
        agenda_aux = agenda_aux->esq;
      }
      else{
        agenda_aux = agenda_aux->dir;
      }
    }
    return agenda_aux->reserva;
  }
  return NULL;
}

  /* Remove o nó com a reserva fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. */
Agenda *abb_remove_agenda(Agenda *raiz, Reserva *reserva) {
  if(raiz == NULL){
    return NULL;
  }
  Agenda *z = abb_busca_agenda(raiz,chave);
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

Reserva *em_ordem(Agenda *agenda, int id, int codigo){
  em_ordem(agenda->esq,id,codigo);
  if (agenda->reserva->codigo == codigo && agenda->reserva->passageiro->id == id){
    return agenda->reserva;
  }
  em_ordem(agenda->dir,id,codigo);
}
