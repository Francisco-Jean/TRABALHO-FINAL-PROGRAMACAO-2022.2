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

Agenda *abb_no_remove(Agenda *raiz,Data *data){
  if (raiz==NULL){
    printf("Valor não encontrado");
    return NULL;
  }
  //if ()
  //}
}

Data * data_cria(int dia, int mes, int ano){
  Data *novaData=(Data *)malloc(sizeof(Data));
  novaData->dia=dia;
  novaData->mes=mes;
  novaData->ano=ano;
  return novaData;
}

void print_data(Data *data) {
  if(data != NULL) {
    printf("Data: %p\n", data);
    printf("\t.Dia=%d\n", data->dia);
    printf("\t.Mes=%d\n", data->mes);
    printf("\t.Ano=%d\n", data->ano);
  }
}
    
/*
 * Retorna:
 *    1, se data1 > data2;
 *   -1, se data1 < data2;
 *    0, caso contrario (data1 == data2)
 */
int data_compara(Data *data1, Data *data2){
  if (data1->ano > data2->ano) {
    return 1;
  }
  if(data1->ano < data2->ano) {
    return -1;
  }
  if(data1->mes > data1->mes) {
    return 1;
  }
  if(data1->mes < data2->mes) {
    return -1;
  }
  if(data1->dia > data2->dia) {
    return 1;
  }
  if(data1->dia < data2->dia) {
    return -1;
  }
  return 0;
}



//