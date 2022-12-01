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

Reserva *cria_reserva(int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(verifica_dados(codigo,data_viagem,passageiro,voo,assento) == 1){
    
  }
  Reserva *reserva = (Reserva*) malloc(sizeof(Reserva));
  reserva->codigo = codigo;
  reserva->data_viagem = data_viagem;
  reserva->passageiro = passageiro;
  reserva->voo = voo;
  reserva->assento = assento;
  return reserva;
}

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


Reserva *em_ordem(Agenda *agenda, int id, int codigo){
  if(agenda->esq != NULL){
    em_ordem(agenda->esq,id,codigo);
  }
  if (agenda->reserva->codigo == codigo && agenda->reserva->passageiro->id == id){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem(agenda->dir,id,codigo);
  }
  return NULL;
}

//Faz a verificação se exite o codigo passado, o passageiro, o voo, a data e o assento
int verifica_dados(int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(codigo == 0 || data_viagem == NULL || passageiro == NULL || voo == NULL || assento<0 ){
    return 0;
  }
  return 1;
}

int verifica_reserva(Agenda *raiz,Data *data_viagem,int codigo,Voo *voo,Assento assento,Passageiro *passageiro){
  if(busca_codigo(codigo) != 0 && abb_busca_reserva(raiz, passageiro->id, codigo,data_viagem) != NULL &&)
  
}
