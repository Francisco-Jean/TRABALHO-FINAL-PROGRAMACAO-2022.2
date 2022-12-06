#include "hash.h"
#include "AgendaReservas.h"
#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

/*struct data {
  int dia;
  int mes;
  int ano;
};*/

/*struct voo {
  int codigo;
  char *origem;
  char *destino;
};*/

/*struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};*/

/*struct lista_voo {
  struct no_voo *primeiro;
};*/

/*struct passageiro {
  int id;
  char *nome;
  char *endereco;
};*/

/*struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};*/

/*struct lista_passageiro {
  struct no_passageiro *primeiro;
};*/

/*struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};*/

/*struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};*/

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

Trecho *cria_trecho(Reserva *reserva) {
  Trecho *novoTrecho = (Trecho *)malloc(sizeof(Trecho));
  novoTrecho->reserva = reserva;
}
  

// ↓↓ Cria, aloca espaço pra tabela hash e atribui NULO pra cada ponteiro-posição do vetor ↓↓ //
TabelaViagem *cria_tabela(int tamanho) {
  TabelaViagem *novaTabela = (TabelaViagem *)malloc(sizeof(TabelaViagem));
  novaTabela->tamanho = tamanho;
  novaTabela->tabela_hash = (Viagem *)malloc(tamanho * sizeof(Viagem));
  // Atribuindo nulo pra cada posição do vetor pra marcar quando tem conteúdo ou
  // não
  for (int i = 0; i < tamanho; i++) {
    novaTabela->tabela_hash[i].trechos = NULL;
  }
}


