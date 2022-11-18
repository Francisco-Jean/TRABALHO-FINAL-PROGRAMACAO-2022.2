#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
  int dia;
  int mes;
  int ano;
};

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

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
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

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};

Passageiro *cria_passageiro(int id,char *nome, char *endereco){
  if(teste_id(id) == 1){
    return NULL;
  }
  Passageiro *passageiro = (Passageiro*) malloc(sizeof(Passageiro));
  passageiro->id = id;
  strcpy(passageiro->nome, nome);
  strcpy(passageiro->endereco, endereco);
  return passageiro;
}
Passageiro remover_passageiro(Passageiro **passageiro){
  if(passageiro != NULL){
    free(*passageiro);
    *passageiro = NULL;
  }
}
  
  