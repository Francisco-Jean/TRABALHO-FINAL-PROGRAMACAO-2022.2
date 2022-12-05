#include "AgendaReservas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  Agenda *raiz;
};

//FUNÇOES DE RESERVA

Reserva *cria_reserva(Agenda *raiz,int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(verifica_dados(codigo,data_viagem,passageiro,voo,assento) == 0 && verifica_reserva(raiz,codigo,data_viagem,passageiro,voo,assento) == 0){
    int id; char nome[30];char endereco[30];
    int codigo; char origem[30];char destino[30];
    passageiroAcessa(passageiro, &id, nome, endereco);
    vooAcessa(voo, &codigo, origem, destino);
    if(strcmp(endereco,origem) == 0){
      editarPassageiro(passageiro,id, nome,destino);
      Reserva *reserva = (Reserva*) malloc(sizeof(Reserva));
      reserva->codigo = codigo;
      reserva->data_viagem = data_viagem;
      reserva->passageiro = passageiro;
      reserva->voo = voo;
      reserva->assento = assento;
      return reserva;
    }
  }
  return NULL;
}

void edita_reserva(Agenda *raiz,Reserva *reserva,int codigo,Data *data_viagem, Passageiro *passageiro, Voo *voo,Assento assento){
  if(reserva!= NULL && verifica_reserva(raiz,codigo,data_viagem,passageiro,voo,assento == 1)){
    int id; char nome[30];char endereco[30];
    int codigo; char origem[30];char destino[30];
    passageiroAcessa(passageiro, &id, nome, endereco);
    vooAcessa(voo, &codigo, origem, destino);
    if(strcmp(endereco,origem) == 0){
      reserva->codigo = codigo;
      reserva->data_viagem = data_viagem;
      reserva->passageiro = passageiro;
      reserva->voo = voo;
      reserva->assento = assento;
    }
  }
}

void remove_reserva(Reserva **reserva){
  if(reserva!=NULL){
    free(reserva);
    *reserva = NULL;
  }
}

void reserva_acessa(Reserva *reserva, int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo, Assento assento){
  if(reserva == NULL){
    codigo = -1;
    data_viagem = NULL;
    passageiro = NULL;
    voo= NULL;
    assento = -1;
  }
  else{
    codigo = reserva->codigo;
    data_viagem = reserva->data_viagem;
    passageiro = reserva->passageiro;
    voo= reserva->voo;
    assento = reserva->assento;
  }
}

/* Retorna o codigo da reserva ou '#' caso o nó seja NULL. */
int abb_codigo_reserva(Reserva *reserva) {
  if(reserva == NULL){
    return '#';
  }
  return reserva->codigo;
}

//FUNÇOES DE AGENDA

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
  return agenda;
}



/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */

// ADD função de contagem da data
Agenda *abb_insere_agenda(Agenda *agenda, Agenda *raiz) {
  if (agenda->reserva == NULL) {
    return NULL;
  }
  Agenda *aux1 = raiz;
  Agenda *aux2 = NULL;
  int data1 = data(agenda->reserva->data_viagem);
    int data2 = data(aux1->reserva->data_viagem);
    int data3 = data(aux2->reserva->data_viagem);
  
  while (aux1 != NULL) {
    aux2 = aux1;
    if (data1 < data2) {
      aux1 = aux1->esq;
    }
    else if (data1 > data2) {
      aux1 = aux1->dir;
    }
    else if (data1 == data3){
      return NULL;
    }
  }
  
  if (data1 < data3) {
    aux2->esq = agenda;
  }
  else {
    aux2->dir = agenda;
  }
  return raiz;
}

/* Procura o reserva pelo id e codigo. Retorna a reserva caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
Reserva *abb_busca_reserva_codigo(Agenda *raiz,int id, int codigo) {
  if(id<0 || codigo <= 0){
    return NULL;
  }
  int id_aux; char nome[30];char endereco[30];
  passageiroAcessa(raiz->reserva->passageiro, &id, nome, endereco);
  Reserva *reserva = em_ordem(raiz,id_aux);
  return reserva;
}


Reserva *abb_busca_reserva_data(Agenda *raiz,int id, Data *data_viagem) {
  if(id<0 || codigo<0 || data_viagem == NULL){
    return NULL;
  }
  if(id != 0 && codigo == 0 && data_viagem != NULL){
    Agenda *agenda_aux = raiz;
    int data1 = data(agenda_aux->reserva->data_viagem);
    int data2 = data(data_viagem);
    int id_aux; char nome[30];char endereco[30];
    int codigo; char origem[30];char destino[30];
    passageiroAcessa(agenda_aux->reserva->passageiro, &id, nome, endereco);
    while(data1 != data2 && id_aux != id){
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


//Faz a verificação se exite o codigo passado, o passageiro, o voo, a data e o assento
int verifica_dados(int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(codigo <= 0 || data_viagem == NULL || passageiro == NULL || voo == NULL || assento<0 ){
    return 0;
  }
  return 1;
}

int verifica_reserva(Agenda *raiz,int codigo,Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  int id; char nome[30];char endereco[30];
  passageiroAcessa(passageiro, &id, nome, endereco);
  if(busca_codigo(raiz,codigo) == 0 && abb_busca_reserva_data(raiz, id,data_viagem) == NULL){
    return 0;
  }
  return 1;
}

int data(Data *data_viagem){
  int dia = data_viagem->dia;
  int mes = data_viagem->mes * 30;
  int ano = data_viagem->ano * 365;
  int soma = dia+mes+ano;
  return soma;
}

int busca_codigo(Agenda *raiz,int codigo_reserva){
  if(codigo_reserva != 0){
    Reserva *codigo = em_ordem2(raiz,codigo_reserva);
    if(codigo != NULL){
      return 1;
    }
  }
  return 0;
}

Reserva *em_ordem(Agenda *agenda, int id,int codigo){
  if(agenda->esq != NULL){
    em_ordem(agenda->esq,id);
  }
  int id_aux; char nome[30];char endereco[30];
  passageiroAcessa(agenda->reserva->passageiro, &id, nome, endereco);
  if (id_aux == id && ){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem(agenda->dir,id);
  }
  return NULL;
}

Reserva *em_ordem2(Agenda *agenda,int codigo){
  if(agenda->esq != NULL){
    em_ordem2(agenda->esq,codigo);
  }
  if (agenda->reserva->codigo == codigo){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem2(agenda->dir,codigo);
  }
  return NULL;
}